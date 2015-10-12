/// App using the Arugments class
#include <iostream>

#include "Arguments.h"


int main( int argc, char* argv[] )
{
    using namespace std;

    try
    {
        Arguments args(argc, argv);
		
		Arguments args2(args);
		Arguments args3(args2);
		args3 = args3;

        cout << "Name of the application: " 
			 << args.appName() 
			 << endl;
		cout << "Number of parameters = " 
			 << args.count()
			 << endl;

        for ( int i = 0; i < args.count(); ++i )
        {
            cout << args[i] << endl;
        }
		
		cout << "copy constructor" << endl;
		cout << "number of parameters = "<< args2.count() << endl;
		for ( int i = 0; i < args2.count(); ++i )
        {
            cout << args2[i] << endl;
        }
		
		cout << "copy constructor using = operator" << endl;
		cout << "number of parameters = "<< args3.count() << endl;
		for (int i = 0; i < args3.count(); ++i)
		{
			cout << args3[i] << endl;
		}
		
    }
    /// This will catch throws from the try block with an integer param
    catch (int e)
    {
        cerr << "Construction error occured..." << endl;
    }
    /// This will catch throws from the try block with a size_t param
    catch (size_t e)
    {
        cerr << "Out of range error occured ..." << endl;
    }

    cout << "Ending application... " << endl;
    return 0;
}
