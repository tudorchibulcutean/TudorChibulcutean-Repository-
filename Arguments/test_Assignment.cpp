#include "gtest/gtest.h"
#include "Arguments.h"

Arguments initialObject()
{
	char * arg[3] = {(char*) "AppName", (char*) "arg1Name", (char*) "arg2Name"};
	Arguments args(3, arg);	
	return args;
}

TEST(AssignmentOperator, ValidArguments)
{
	Arguments args = initialObject();
	EXPECT_EQ(args[0], "arg1Name");
	EXPECT_EQ(args[1], "arg2Name");
}

TEST(AssignmentOperatorObject, ValidData)
{
	char * arg[1] = {(char*)"ceva"};
	Arguments args = initialObject();
	Arguments copyArgs(1, arg);
	copyArgs = args;
	
	EXPECT_EQ(copyArgs.appName(), args.appName());
	EXPECT_EQ(copyArgs[0], args[0]);
	EXPECT_EQ(copyArgs[1], args[1]);
}