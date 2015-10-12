#include <iostream>

#include "Arguments.h"

using namespace std;

Arguments::Arguments(int argc, char* argv[])
{
    try
    {
        if ( argc < 0 || argv == 0 )
        {
            throw argc;
        }
        else
        {
            /// todo: Set app to be the first item from argv
			app = argv[0];
			
            /// todo: Save the remaining from argv into the args vector (push_back)
			for(int i = 1; i < argc; i++)
			{
				args.push_back(argv[i]);
			}
        }
    }
    catch (int e)
    {
        cerr << "error: constructing argument object..." << endl;
        throw;
    }
}

Arguments::Arguments(const Arguments& rhs):
	args(rhs.args),
	app(rhs.app)
{
}

Arguments& Arguments::operator=(const Arguments& rhs)
{
	if (this == &rhs)
	{
		cout << "Object already exists! " << endl;
		return *this;
	}
	else
	{
	cout << "Objects are equal! " << endl;
	args = rhs.args;
	app = rhs.app;
	
	return *this;	
	} 
} 


const string&
Arguments::operator[](const size_t i) const
{
    try
    {
        if ( i >= args.size() ) throw i;
    }
    catch(size_t e)
    {
        cerr << "error: index out of range " << e << endl;
        throw;
    }
    /// todo: return argument on index
	return args[i];
}

int Arguments::count() const
{
	return args.size();
}

std::string Arguments::appName() const
{
	return app;
}
