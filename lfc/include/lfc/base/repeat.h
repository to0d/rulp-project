#ifndef __LFC_BASE_REPEAT_H__
#define __LFC_BASE_REPEAT_H__

#define __LFC_REP1(x) x                
#define __LFC_REP2(x) x , x              
#define __LFC_REP3(x) x , x , x            
#define __LFC_REP4(x) x , x , x , x          
#define __LFC_REP5(x) x , x , x , x , x        
#define __LFC_REP6(x) x , x , x , x , x , x      
#define __LFC_REP7(x) x , x , x , x , x , x , x    
#define __LFC_REP8(x) x , x , x , x , x , x , x , x  
#define __LFC_REP9(x) x , x , x , x , x , x , x , x , x

#define __LFC_X1(x) x##1                
#define __LFC_X2(x) x##1 , x##2              
#define __LFC_X3(x) x##1 , x##2 , x##3            
#define __LFC_X4(x) x##1 , x##2 , x##3 , x##4          
#define __LFC_X5(x) x##1 , x##2 , x##3 , x##4 , x##5        
#define __LFC_X6(x) x##1 , x##2 , x##3 , x##4 , x##5 , x##6      
#define __LFC_X7(x) x##1 , x##2 , x##3 , x##4 , x##5 , x##6 , x##7    
#define __LFC_X8(x) x##1 , x##2 , x##3 , x##4 , x##5 , x##6 , x##7 , x##8  
#define __LFC_X9(x) x##1 , x##2 , x##3 , x##4 , x##5 , x##6 , x##7 , x##8 , x##9

#define __LFC_XY1(x,y) x y##1                
#define __LFC_XY2(x,y) x y##1 , x y##2              
#define __LFC_XY3(x,y) x y##1 , x y##2 , x y##3            
#define __LFC_XY4(x,y) x y##1 , x y##2 , x y##3 , x y##4          
#define __LFC_XY5(x,y) x y##1 , x y##2 , x y##3 , x y##4 , x y##5        
#define __LFC_XY6(x,y) x y##1 , x y##2 , x y##3 , x y##4 , x y##5 , x y##6      
#define __LFC_XY7(x,y) x y##1 , x y##2 , x y##3 , x y##4 , x y##5 , x y##6 , x y##7    
#define __LFC_XY8(x,y) x y##1 , x y##2 , x y##3 , x y##4 , x y##5 , x y##6 , x y##7 , x y##8  
#define __LFC_XY9(x,y) x y##1 , x y##2 , x y##3 , x y##4 , x y##5 , x y##6 , x y##7 , x y##8 , x y##9

#define __LFC_X1Y1(x,y) x##1  y##1                          
#define __LFC_X2Y2(x,y) x##1  y##1   , x##2  y##2                     
#define __LFC_X3Y3(x,y) x##1  y##1   , x##2  y##2 , x##3  y##3                  
#define __LFC_X4Y4(x,y) x##1  y##1   , x##2  y##2 , x##3  y##3 , x##4  y##4               
#define __LFC_X5Y5(x,y) x##1  y##1   , x##2  y##2 , x##3  y##3 , x##4  y##4 , x##5  y##5            
#define __LFC_X6Y6(x,y) x##1  y##1   , x##2  y##2 , x##3  y##3 , x##4  y##4 , x##5  y##5 , x##6  y##6         
#define __LFC_X7Y7(x,y) x##1  y##1   , x##2  y##2 , x##3  y##3 , x##4  y##4 , x##5  y##5 , x##6  y##6 , x##7  y##7      
#define __LFC_X8Y8(x,y) x##1  y##1   , x##2  y##2 , x##3  y##3 , x##4  y##4 , x##5  y##5 , x##6  y##6 , x##7  y##7 , x##8  y##8   
#define __LFC_X9Y9(x,y) x##1  y##1   , x##2  y##2 , x##3  y##3 , x##4  y##4 , x##5  y##5 , x##6  y##6 , x##7  y##7 , x##8  y##8 , x##9  y##9

#define  __LFC_XY1Z(x,y, z) x y##1 z                
#define  __LFC_XY2Z(x,y, z) x y##1 z , x y##2 z              
#define  __LFC_XY3Z(x,y, z) x y##1 z , x y##2 z , x y##3 z            
#define  __LFC_XY4Z(x,y, z) x y##1 z , x y##2 z , x y##3 z , x y##4 z          
#define  __LFC_XY5Z(x,y, z) x y##1 z , x y##2 z , x y##3 z , x y##4 z , x y##5 z        
#define  __LFC_XY6Z(x,y, z) x y##1 z , x y##2 z , x y##3 z , x y##4 z , x y##5 z , x y##6 z      
#define  __LFC_XY7Z(x,y, z) x y##1 z , x y##2 z , x y##3 z , x y##4 z , x y##5 z , x y##6 z , x y##7 z    
#define  __LFC_XY8Z(x,y, z) x y##1 z , x y##2 z , x y##3 z , x y##4 z , x y##5 z , x y##6 z , x y##7 z , x y##8 z  
#define  __LFC_XY9Z(x,y, z) x y##1 z , x y##2 z , x y##3 z , x y##4 z , x y##5 z , x y##6 z , x y##7 z , x y##8 z , x y##9 z

#define  __LFC_XY1Z1(x,y,z) x y##1 z##1                
#define  __LFC_XY2Z2(x,y,z) x y##1 z##1 , x y##2 z##2              
#define  __LFC_XY3Z3(x,y,z) x y##1 z##1 , x y##2 z##2 , x y##3 z##3            
#define  __LFC_XY4Z4(x,y,z) x y##1 z##1 , x y##2 z##2 , x y##3 z##3 , x y##4 z##4          
#define  __LFC_XY5Z5(x,y,z) x y##1 z##1 , x y##2 z##2 , x y##3 z##3 , x y##4 z##4 , x y##5 z##5        
#define  __LFC_XY6Z6(x,y,z) x y##1 z##1 , x y##2 z##2 , x y##3 z##3 , x y##4 z##4 , x y##5 z##5 , x y##6 z##6      
#define  __LFC_XY7Z7(x,y,z) x y##1 z##1 , x y##2 z##2 , x y##3 z##3 , x y##4 z##4 , x y##5 z##5 , x y##6 z##6 , x y##7 z##7    
#define  __LFC_XY8Z8(x,y,z) x y##1 z##1 , x y##2 z##2 , x y##3 z##3 , x y##4 z##4 , x y##5 z##5 , x y##6 z##6 , x y##7 z##7 , x y##8 z##8  
#define  __LFC_XY9Z9(x,y,z) x y##1 z##1 , x y##2 z##2 , x y##3 z##3 , x y##4 z##4 , x y##5 z##5 , x y##6 z##6 , x y##7 z##7 , x y##8 z##8 , x y##9 z##9

#define  __LFC_CONST_X1Y1(x,y) const x##1& y##1                
#define  __LFC_CONST_X2Y2(x,y) const x##1& y##1 , const x##2& y##2              
#define  __LFC_CONST_X3Y3(x,y) const x##1& y##1 , const x##2& y##2 , const x##3& y##3            
#define  __LFC_CONST_X4Y4(x,y) const x##1& y##1 , const x##2& y##2 , const x##3& y##3 , const x##4& y##4          
#define  __LFC_CONST_X5Y5(x,y) const x##1& y##1 , const x##2& y##2 , const x##3& y##3 , const x##4& y##4 , const x##5& y##5        
#define  __LFC_CONST_X6Y6(x,y) const x##1& y##1 , const x##2& y##2 , const x##3& y##3 , const x##4& y##4 , const x##5& y##5 , const x##6& y##6      
#define  __LFC_CONST_X7Y7(x,y) const x##1& y##1 , const x##2& y##2 , const x##3& y##3 , const x##4& y##4 , const x##5& y##5 , const x##6& y##6 , const x##7& y##7    
#define  __LFC_CONST_X8Y8(x,y) const x##1& y##1 , const x##2& y##2 , const x##3& y##3 , const x##4& y##4 , const x##5& y##5 , const x##6& y##6 , const x##7& y##7 , const x##8& y##8  
#define  __LFC_CONST_X9Y9(x,y) const x##1& y##1 , const x##2& y##2 , const x##3& y##3 , const x##4& y##4 , const x##5& y##5 , const x##6& y##6 , const x##7& y##7 , const x##8& y##8 , const x##9& y##9

#define __LFC_X1Y1Z(x,y,z) x##1 y##1 z                              
#define __LFC_X2Y2Z(x,y,z) x##1 y##1 z , x##2 y##2 z                          
#define __LFC_X3Y3Z(x,y,z) x##1 y##1 z , x##2 y##2 z , x##3 y##3 z                      
#define __LFC_X4Y4Z(x,y,z) x##1 y##1 z , x##2 y##2 z , x##3 y##3 z , x##4 y##4 z                  
#define __LFC_X5Y5Z(x,y,z) x##1 y##1 z , x##2 y##2 z , x##3 y##3 z , x##4 y##4 z , x##5 y##5 z              
#define __LFC_X6Y6Z(x,y,z) x##1 y##1 z , x##2 y##2 z , x##3 y##3 z , x##4 y##4 z , x##5 y##5 z , x##6 y##6 z          
#define __LFC_X7Y7Z(x,y,z) x##1 y##1 z , x##2 y##2 z , x##3 y##3 z , x##4 y##4 z , x##5 y##5 z , x##6 y##6 z , x##7 y##7 z      
#define __LFC_X8Y8Z(x,y,z) x##1 y##1 z , x##2 y##2 z , x##3 y##3 z , x##4 y##4 z , x##5 y##5 z , x##6 y##6 z , x##7 y##7 z , x##8 y##8   
#define __LFC_X9Y9Z(x,y,z) x##1 y##1 z , x##2 y##2 z , x##3 y##3 z , x##4 y##4 z , x##5 y##5 z , x##6 y##6 z , x##7 y##7 z , x##8 y##8 , x##9 y##9

#endif // __LFC_BASE_REPEAT_H__

