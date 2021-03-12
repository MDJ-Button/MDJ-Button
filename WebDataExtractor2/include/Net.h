#ifndef NET_H
#define NET_H

#include <Python.h>

#include <iostream>
#include <fstream>

class Net
{
    public:
        Net();

        std::string CheckConnection()
        {
            std::ifstream ScriptExist("CheckConnection.py");

            if(!ScriptExist)
            {
                return "ScriptMissing";
            }

            //Initialize the python instance
            Py_Initialize(); std::cout << "CheckConnection() " << "Initialize Python" << "\n";

            PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;

            pName = PyUnicode_FromString((char*)"CheckConnection");
            pModule = PyImport_Import(pName);
            pFunc = PyObject_GetAttrString(pModule, (char*)"CheckConnection");
            pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)"http://216.58.192.142"));
            pValue = PyObject_CallObject(pFunc, pArgs);

            std::string result = _PyUnicode_AsString(pValue);

            std::cout << "Returning " << result;

            //Close the python instance
            Py_Finalize(); std::cout << "\n" << "CheckConnection() " << "Finalize Python" << "\n\n";
            return result;
        }

        std::string PageExists(std::string FilePath)
        {
            int sizeof_FilePath = FilePath.length();
            char FilePath_char[sizeof_FilePath];
            strcpy(FilePath_char, FilePath.c_str());

            std::ifstream ScriptExist("ServerFileExists.py");

            if(!ScriptExist)
            {
                return "ScriptMissing";
            }

            //Initialize the python instance
            Py_Initialize(); std::cout << "ServerFileExists() " << "Initialize Python" << "\n";

            PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;

            pName = PyUnicode_FromString((char*)"ServerFileExists");
            pModule = PyImport_Import(pName);
            pFunc = PyObject_GetAttrString(pModule, (char*)"FileExists");
            pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)FilePath_char));
            pValue = PyObject_CallObject(pFunc, pArgs);

            std::string result = _PyUnicode_AsString(pValue);

            std::cout << "Returning " << result;

            //Close the python instance
            Py_Finalize(); std::cout << "\n" << "ServerFileExists() " << "Finalize Python" << "\n\n";
            return result;
        }

        std::string GetPageSource(std::string FilePath)
        {
            int sizeof_FilePath = FilePath.length();
            char FilePath_char[sizeof_FilePath];
            strcpy(FilePath_char, FilePath.c_str());

            std::ifstream ScriptExist("GetServerFileData.py");

            if(!ScriptExist)
            {
                return "ScriptMissing";
            }

            //Initialize the python instance
            Py_Initialize(); std::cout << "GetServerFileData() " << "Initialize Python" << "\n";

            PyObject *pName, *pModule, *pFunc, *pArgs, *pValue;

            pName = PyUnicode_FromString((char*)"GetServerFileData");
            pModule = PyImport_Import(pName);
            pFunc = PyObject_GetAttrString(pModule, (char*)"GetFile");
            pArgs = PyTuple_Pack(1, PyUnicode_FromString((char*)FilePath_char));
            pValue = PyObject_CallObject(pFunc, pArgs);

            std::string result = _PyUnicode_AsString(pValue);

            std::cout << "Returning " << result;

            //Close the python instance
            Py_Finalize(); std::cout << "\n" << "GetServerFileData() " << "Finalize Python" << "\n\n";
            return result;
        }

    protected:

    private:
};

#endif // NET_H
