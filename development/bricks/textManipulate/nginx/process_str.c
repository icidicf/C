#include <sys/types.h>

typedef struct {
    size_t      len;
    unsigned char     *data;
} ngx_str_t; 

void process_str(ngx_str_t *in)                                              
  {                                                                                   
      char *pos = (char *)in->data;                                                   
      char *prev_pos;                                                                 
      char *end = (char *)in->data + in->len;                                         
      int index = 0;                                                            
      ngx_str_t items[2] ;                                                            
                                                                                      
      dd("the str to process is %V", in);                                             
      items[index].data = (unsigned char *)pos;                                              
      for (; pos != end; pos ++ ) {                                                   
          if (*pos == ' ' || *pos == '\n') {                                          
              while (*pos == ' ' && pos != end)                                       
                  pos ++;                                                             
                                                                                      
              items[index].len = prev_pos + 1 - (char *)items[index].data;            
              dd("index %d len is %d, data is %V",index, items[index].len,            
                      &items[index]);                                                 
                                                                                      
              index ++;                                                               
              if (*pos == '\n') {                                                     
                  if (index < 2) {                                                    
                      dd("formant error index %d is less than 1", index);             
                  }                                                                   
                  dd("get ip %V, get ttl %V ", &items[0], &items[1]);                 
                  index = 0;                                                          
              } else {                                                                
                  items[index].data = (unsigned char *)pos;                                  
              }                                                                       
          } else {                                                                    
              prev_pos = pos;                                                         
          }                                                                           
      }                                                                               
  }
