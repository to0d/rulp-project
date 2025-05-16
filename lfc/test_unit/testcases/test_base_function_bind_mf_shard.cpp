#include "unitest_base.h"
#include "lfc/base/function.h"
#include "lfc/base/function_impl.h"

using namespace lfc;

namespace __ctest_inner_function{

  class __inner_class3{
  public:

    int fun0(){
      return 0;
    }

    int fun1(int v1){
      return 1;
    }

    int fun2(int v1,int v2){
      return 2;
    }

    int fun3(int v1,int v2,int v3){
      return 3;
    }

    int fun4(int v1,int v2,int v3,int v4){
      return 4;
    }

    int fun5(int v1,int v2,int v3,int v4, int v5){
      return 5;
    }

    int fun6(int v1,int v2,int v3,int v4, int v5,int v6){
      return 6;
    }

    int fun7(int v1,int v2,int v3,int v4, int v5,int v6,int v7){
      return 7;
    }

    int fun8(int v1,int v2,int v3,int v4, int v5,int v6,int v7,int v8){
      return 8;
    }

    int fun9(int v1,int v2,int v3,int v4, int v5,int v6,int v7,int v8,int v9){
      return 9;
    }

  };
}



TEST(base_function, test_bind_mf_shard)
{

  //f0
  { 
    lfc::function<int()>  f;
    EXPECT_TRUE(f == NULL);

    f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(),0);
  }

  {
    lfc::function<int(void)>  f;
    EXPECT_TRUE(f == NULL);

    f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(),0);
  }

  //f1
  {
    lfc::function<int(int)>  f;
    EXPECT_TRUE(f == NULL);

    f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1),1);

    f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1),0);
  }

  {
    lfc::function<int(int)>  f;
    EXPECT_TRUE(f == NULL);

    f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1),1);

    f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1),0);
  }

  //f2
  {
    lfc::function<int(int,int)>  f;
    EXPECT_TRUE(f == NULL);

    f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1,1),2);

    f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1,1),1);

    f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1,1),0);
  }

  {
    lfc::function<int(int,int)>  f;
    EXPECT_TRUE(f == NULL);

    f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1,1),2);

    f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1,1),1);

    f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(1,1),0);
  }


  //f3
  {
    lfc::function<int(int,int,int)>  f;
    EXPECT_TRUE(f == NULL);

    f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(0,0,0),3);

    f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(0,0,0),2);

    f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(0,0,0),1);

    f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(0,0,0),0);
  }

  {
    lfc::function<int(int,int,int)>  f;
    EXPECT_TRUE(f == NULL);

    f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(0,0,0),3);

    f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(0,0,0),2);

    f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(0,0,0),1);

    f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
    EXPECT_TRUE(f != NULL);
    EXPECT_EQ(f(0,0,0),0);
  }

    //f4
    {
        lfc::function<int(int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),0);
    }

    {
        lfc::function<int(int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0),0);
    }

    //f5
    {
        lfc::function<int(int,int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),5);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),0);
    }

    {
        lfc::function<int(int,int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),5);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0),0);
    }

    //f6
    {
        lfc::function<int(int,int,int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun6,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),6);

        f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),5);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),0);
    }

    {
        lfc::function<int(int,int,int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun6,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),6);

        f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),5);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0),0);
    }

    //f7
    {
        lfc::function<int(int,int,int,int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun7,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),7);

        f = bind(&__ctest_inner_function::__inner_class3::fun6,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),6);

        f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),5);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),0);
    }

    {
        lfc::function<int(int,int,int,int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun7,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),7);

        f = bind(&__ctest_inner_function::__inner_class3::fun6,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),6);

        f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),5);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0),0);
    }

    //f8
    {
        lfc::function<int(int,int,int,int,int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun8,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7,_8);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),8);

        f = bind(&__ctest_inner_function::__inner_class3::fun7,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),7);

        f = bind(&__ctest_inner_function::__inner_class3::fun6,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),6);

        f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),5);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),0);
    }

    {
        lfc::function<int(int,int,int,int,int,int,int,int)>  f;
        EXPECT_TRUE(f == NULL);

        f = bind(&__ctest_inner_function::__inner_class3::fun8,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7,_8);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),8);

        f = bind(&__ctest_inner_function::__inner_class3::fun7,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),7);

        f = bind(&__ctest_inner_function::__inner_class3::fun6,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),6);

        f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),5);

        f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),4);

        f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),3);

        f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),2);

        f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),1);

        f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
         EXPECT_TRUE(f != NULL);
        EXPECT_EQ(f(0,0,0,0,0,0,0,0),0);
    }

//     //f9
//     {
//         function<int(int,int,int,int,int,int,int,int,int)>  f;
//         EXPECT_TRUE(f == NULL);
// #ifdef __TEST_BOOST_EXTRA__
//         f = bind(&__ctest_inner_function::__inner_class3::fun9,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7,_8,_9);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),9);
// #endif
//         f = bind(&__ctest_inner_function::__inner_class3::fun8,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7,_8);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),8);

//         f = bind(&__ctest_inner_function::__inner_class3::fun7,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),7);

//         f = bind(&__ctest_inner_function::__inner_class3::fun6,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),6);

//         f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),5);

//         f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),4);

//         f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),3);

//         f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),2);

//         f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),1);

//         f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),0);
//     }

//     {
//         function<int(int,int,int,int,int,int,int,int,int)>  f;
//         EXPECT_TRUE(f == NULL);
// #ifdef __TEST_BOOST_EXTRA__
//         f = bind(&__ctest_inner_function::__inner_class3::fun9,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7,_8,_9);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),9);
// #endif
//         f = bind(&__ctest_inner_function::__inner_class3::fun8,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7,_8);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),8);

//         f = bind(&__ctest_inner_function::__inner_class3::fun7,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6,_7);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),7);

//         f = bind(&__ctest_inner_function::__inner_class3::fun6,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5,_6);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),6);

//         f = bind(&__ctest_inner_function::__inner_class3::fun5,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4,_5);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),5);

//         f = bind(&__ctest_inner_function::__inner_class3::fun4,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3,_4);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),4);

//         f = bind(&__ctest_inner_function::__inner_class3::fun3,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2,_3);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),3);

//         f = bind(&__ctest_inner_function::__inner_class3::fun2,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1,_2);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),2);

//         f = bind(&__ctest_inner_function::__inner_class3::fun1,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3),_1);
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),1);

//         f = bind(&__ctest_inner_function::__inner_class3::fun0,std::shared_ptr<__ctest_inner_function::__inner_class3>(new __ctest_inner_function::__inner_class3));
//          EXPECT_TRUE(f != NULL);
//         EXPECT_EQ(f(0,0,0,0,0,0,0,0,0),0);
//     }
}

