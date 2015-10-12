#include "gtest/gtest.h"
#include "Arguments.h"

Arguments initializeObject()
{
	char * arg[3] = {(char*)"appName", (char*)"arg1Name", (char*)"arg2Name"};
	Arguments args(3, arg);	
	return args;
}

TEST(CopyConstructorTest, test_appName)
{
	Arguments args = initializeObject();
	Arguments copyArgs(args);
	EXPECT_EQ(copyArgs.appName(), args.appName());
	EXPECT_NE(copyArgs.appName(), "othername");
}

TEST(CopyConstructorTest, test_arguments)
{
	Arguments args = initializeObject();
	Arguments copyArgs(args);
	EXPECT_EQ(copyArgs[0], args[0]);
	EXPECT_EQ(copyArgs[1], args[1]);
}

TEST(CopyConstructorTest, test_count)
{
	Arguments args = initializeObject();
	Arguments copyArgs(args);
	EXPECT_NE(3, copyArgs.count());
	EXPECT_NE(1, copyArgs.count());
	EXPECT_EQ(copyArgs.count(), args.count());
}