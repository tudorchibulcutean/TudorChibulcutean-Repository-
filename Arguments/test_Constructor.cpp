#include "gtest/gtest.h"
#include "Arguments.h"

// 
TEST(ConstructorTest, test_appName)
{
	char* arg[2] = {(char*) "appName", (char*) "arg1name"};
	Arguments args(2, arg);
	
	EXPECT_EQ("appName", args.appName());
	EXPECT_NE("otherName", args.appName());
}

TEST(ConstructorTest, test_arguments)
{
	char* arg[3] = {(char*) "appName", (char*) "arg1Name", (char*) "arg2Name"};
	Arguments args(3, arg);
	EXPECT_EQ("arg1Name", args[0]);
	EXPECT_EQ("arg2Name", args[1]);
}

TEST(ConstructorTest, test_count)
{
	char* arg[3] = {(char*) "appName", (char*) "arg1Name", (char*) "arg2name"};
	Arguments args(3, arg);
	EXPECT_NE(3, args.count());
	EXPECT_NE(1, args.count());
	EXPECT_EQ(2, args.count());
}

TEST(ConstructorTest, TestInvalidArgc)
{
	char * arg2[0] = {};
	bool hasException = false;
	try
	{
		Arguments args2(-1,arg2);
	}
	catch(int e)
	{
		hasException = true;
	}
	
	EXPECT_EQ(true, hasException);
}

TEST(ConstructorTest, TestInvalidArgc0)
{
	char * arg2[0] = {};
	bool hasException = false;
	try
	{
		Arguments args2(0, arg2);
	}
	catch(int e)
	{
		hasException = true;
	}
	
	EXPECT_EQ(true, hasException);
}

TEST(ConstructorTest, TestInvalidArgv)
{
	char ** arg2 = 0;
	bool hasException = false;
	try
	{
		Arguments args2(2, arg2);
	}
	catch(int e)
	{
		hasException = true;
	}
	
	EXPECT_EQ(true, hasException);
} 
