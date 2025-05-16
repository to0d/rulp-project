// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/memory.h"
#include "lfc/base/macro.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

namespace lfc {

char __dump_hex_to_char(char v){
  if( v <= 9 ){  
    return '0' + v;
  }
  return 'A' + v - 10;
}

std::vector<std::string> dump_memory_hex(void *address, int datasize){

  std::vector<std::string> lines;

#define ROW_A_LINE 16

  if( address == NULL || datasize == 0){
    return {};
  }

  unsigned char *pAddr = (unsigned char*)address;
  int index = 0;

  char buf[ROW_A_LINE*3 + 40]; 
  int  buf_pos;
  
  while (datasize){
    int nCurSize = MIN(datasize, ROW_A_LINE);
    int i = 0;
    
    // Output Hex
    buf_pos = sprintf(buf,"   %05X     ", index);
    while (i < ROW_A_LINE){
      if( i < nCurSize ){
        char c = pAddr[i++];
        buf[buf_pos++ ] = __dump_hex_to_char((c&0xF0) >> 4 );
        buf[buf_pos++ ] = __dump_hex_to_char((c&0x0F) );
      }
      else{ // append '.' if need
        buf[buf_pos++] = '.';
        buf[buf_pos++] = '.';
        ++i;
      }

      if( i % 4 == 0 ){
        buf[buf_pos++] = ' ';// fill a blank
      }
    }
      
    // Output Character 
    i = 0;	
    buf_pos += sprintf(buf+buf_pos, "  - ");
    while ( i < ROW_A_LINE ){
      if( i < nCurSize ){  
        char c = pAddr[i];  
        buf[buf_pos++]  = isgraph(c) ? c : '.';   
      }
      else{
        buf[buf_pos++] = '.';
      }
      ++i;
    }

    buf[buf_pos] = '\0';

    lines.push_back(std::string(buf, buf_pos));

    datasize -= nCurSize;	 // print next line
    pAddr += nCurSize;
    index += ROW_A_LINE;
  }

  return lines;
}

} // namespace lfc