#include <stdio.h>
#include <pthread.h>
#include <curl/curl.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 
#define NUMT 4
 
/*
  List of URLs to fetch.
 
  If you intend to use a SSL-based protocol here you might need to setup TLS
  library mutex callbacks as described here:
 
  https://curl.haxx.se/libcurl/c/threadsafe.html
 
*/ 
struct url_data {                                                                
    size_t size;                                                                 
    char* data;                                                                     
};
const char * const urls[NUMT]= {
  "https://curl.haxx.se/",
  "ftp://cool.haxx.se/",
  "http://www.contactor.se/",
  "www.haxx.se"
};

const char* url_format="http://106.2.81.8/d?dn=data.live.126.net&ip=%s";
//const char* url_format="http://106.2.81.51/d?dn=data.live.126.net&ip=%s";
//const char* url_format="http://192.168.29.160/d?dn=www.baidu.com&ip=%s";
//const char* url_format="http://httpdns-test.c.163.com/d?dn=data.live.126.net&ip=%s/";
 
size_t write_data(void *ptr, size_t size, size_t nmemb, struct url_data *data) { 
//    size_t index = data->size;                                                      
    size_t index = 0;                                                      
    size_t n = (size * nmemb);                                                      
    char* tmp;                                                                      

    data->size += (size * nmemb);                                                   
    
    printf(" data size is %ld\n", data->size);

#ifdef DEBUG                                                                        
    fprintf(stderr, "data at %p size=%ld nmemb=%ld\n", ptr, size, nmemb);           
#endif                                                                              
    tmp = realloc(data->data, data->size + 1); /* +1 for '\0' */                    

    if(tmp) {                                                                       
        data->data = tmp;                                                           
    } else {                                                                        
        if(data->data) {                                                            
            free(data->data);                                                       
        }                                                                           
        fprintf(stderr, "Failed to allocate memory.\n");                            
        return 0;                                                                   
    }                                                                               

    memcpy((data->data + index), ptr, n);                                           
    data->data[data->size] = '\0';                                                  

    return size * nmemb;                                                            
}  


char* get_ip_from_int(int ip) {

    unsigned char bytes[4];

    unsigned char *result = NULL;
    result = calloc(20, sizeof(char));
    if (result == NULL) {
        printf("calloc failed");
        return "";
    }
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;   
    snprintf(result, 20, "%d.%d.%d.%d", bytes[3], bytes[2], bytes[1], bytes[0]);     
    return result;
}


static void *pull_one_url(void *url_in)
{
  CURL *curl;
  CURLcode res;
  int count = 0;
  struct url_data data; 
  pthread_t ptid = pthread_self();

  char url[100];
  while (1 == 1) {
    //  usleep(10000);
      snprintf(url, 100 , url_format, get_ip_from_int(rand()));
      printf("tid %ld count %d, get url is %s\n",(long)ptid, count++, url);
      curl = curl_easy_init();
      curl_easy_setopt(curl, CURLOPT_URL, url);
      /*
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);                  
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);    
      */
      res = curl_easy_perform(curl); /* ignores error */ 
      if(res != CURLE_OK) {
          fprintf(stderr, "curl_easy_perform() failed: %s\n",  
                  curl_easy_strerror(res));
      }
     // printf("%s return data is %s\n",url, data.data);
      curl_easy_cleanup(curl);
  }
 
  return NULL;
}
 
/*
   int pthread_create(pthread_t *new_thread_ID,
   const pthread_attr_t *attr,
   void * (*start_func)(void *), void *arg);
*/ 
 
int main(int argc, char **argv)
{
  pthread_t tid[NUMT];
  int i;
  int error;
 
  /* Must initialize libcurl before any threads are started */ 
  curl_global_init(CURL_GLOBAL_ALL);
  srand(time(NULL));
 
  for(i=0; i< NUMT; i++) {
    error = pthread_create(&tid[i],
                           NULL, /* default attributes please */ 
                           pull_one_url,
                           (void *)urls[i]);
    if(0 != error)
      fprintf(stderr, "Couldn't run thread number %d, errno %d\n", i, error);
    else
      fprintf(stderr, "Thread %d, gets %s\n", i, urls[i]);
  }
 
  /* now wait for all threads to terminate */ 
  for(i=0; i< NUMT; i++) {
    error = pthread_join(tid[i], NULL);
    fprintf(stderr, "Thread %d terminated\n", i);
  }
 
  return 0;
}


