#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <sys/types.h>  
#include <unistd.h>  
#include "lfc/base.h"


int main( void )
{
    int len;
    int rc;
    if( lfc::is_dir("./src") == 0 ) // dir exist
    {   
        printf("Dir exist.\n");
        if( (rc=lfc::rm_dir("./src")) == 0 )
        {   printf("delete succ\n");             
        }
        else
        {   printf("delete fail, rc=%d\n",rc);
            exit(0);
        }
        
        if( lfc::is_dir("./src") == 0 )
        {   printf("why not deleted\n");
            exit(0);            
        }
    }
   
    if( (rc=lfc::mkdirs("./xx/xx/../../////src/test/test2")) == 0 )
    {   printf("mkdir succ\n");      
    }
    else
    {   printf("mkdir fail, rc=%d\n", rc);       
    }
    
    lfc::rm_dir("./src");
    printf("output: done.\n");
    return 0;
}
