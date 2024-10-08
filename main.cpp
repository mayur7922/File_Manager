#include<iostream>
using namespace std;

#include "FileSystemManager.hpp"

int main(){

    string root = "root";
    FileSystemManager * FileSystem = new FileSystemManager(root);

    while(1){

        cout<<endl;
        cout<<"File Manager"<<endl<<endl;
        cout<<endl;

        cout<<endl;
        cout<<"Enter you choice"<<endl;
        cout<<endl;

        cout<<endl;
        cout<<"1 -> Add a file/folder to a given folder"<<endl;
        cout<<"2 -> Move files from one folder to another"<<endl;
        cout<<"3 -> List all files/folder for a given folder"<<endl;
        cout<<"4 -> Search by file names in a folder"<<endl;
        cout<<"5 -> Exit"<<endl;
        cout<<endl;

        int input; cin>>input;

        if(input == 1){
            cout<<endl;
            cout<<"Enter you choice"<<endl;
            cout<<endl;

            cout<<"1 -> To create a Folder"<<endl;
            cout<<"2 -> To create a File"<<endl;

            int input; cin>>input;

            if(input == 1){
                string parentFolder, folderName;
                cout<<"Enter the name of parent folder"<<endl;
                cin>>parentFolder;
                cout<<"Enter the folder name"<<endl;
                cin>>folderName;

                FileSystem -> addFolder(parentFolder, folderName);
                cout<<endl;
                cout<<"Folder added successfully!";
                cout<<endl;
            }
            else if(input == 2){
                string parentFolder, fileName, content;
                cout<<"Enter the name of parent folder"<<endl;
                cin>>parentFolder;
                cout<<"Enter the file name"<<endl;
                cin>>fileName;
                cout<<"Enter the content of the file"<<endl;
                cin>>content;

                FileSystem -> addFile(parentFolder, fileName, content);
                cout<<endl;
                cout<<"File added successfully!";
                cout<<endl;
            }
        }
        else if(input == 2){
            cout<<endl;
            cout<<"Enter you choice"<<endl;
            cout<<endl;

            cout<<"1 -> To move a Folder"<<endl;
            cout<<"2 -> To move a File"<<endl;

            int input; cin>>input;

            if(input == 1){
                string sourceFolder, destinationFolder, folderName;
                cout<<"Enter name of source folder"<<endl;
                cin>>sourceFolder;
                cout<<"Enter name of destination folder"<<endl;
                cin>>destinationFolder;
                cout<<"Enter name of the folder"<<endl;
                cin>>folderName;

                FileSystem -> moveFileOrFolder(sourceFolder,destinationFolder,folderName,1);
                cout<<endl;
                cout<<"Folder moved successfully!";
                cout<<endl;
            }
            else{
                string sourceFolder, destinationFolder, fileName;
                cout<<"Enter name of source folder"<<endl;
                cin>>sourceFolder;
                cout<<"Enter name of destination folder"<<endl;
                cin>>destinationFolder;
                cout<<"Enter name of the file"<<endl;
                cin>>fileName;

                FileSystem -> moveFileOrFolder(sourceFolder,destinationFolder,fileName,0);
                cout<<endl;
                cout<<"File moved successfully!";
                cout<<endl;
            }

        }
        else if(input == 3){
            string folderName;
            cout<<"Enter the folder name : "<<endl;
            cin>>folderName;
            vector<std::string> v = FileSystem -> listContents(folderName);
            cout<<"Contents of the given folder are :" <<endl;
            for(string i : v){
                cout<<i<<endl;
            }
            cout<<endl;
        }
        else if(input == 4){
            cout<<endl;
            cout<<"Enter you choice"<<endl;
            cout<<endl;

            cout<<"1 -> To search for exact file name"<<endl;
            cout<<"2 -> To search for likewise file name"<<endl;

            int input; cin>>input;

            if(input == 1){
                string folderName, fileName;
                cout<<"Enter name of the folder : "<<endl;
                cin>>folderName;
                cout<<"Enter name of the file : "<<endl;
                cin>>fileName;

                string str = FileSystem -> searchFileExactMatch(folderName, fileName);
                if(str != ""){
                    cout<<str<<endl;
                }
                else{
                    cout<<"No file exits with given name"<<endl;
                }
            }
            else{
                string folderName, pattern;
                cout<<"Enter name of the folder : "<<endl;
                cin>>folderName;
                cout<<"Enter the pattern : "<<endl;
                cin>>pattern;

                vector<std::string> v = FileSystem -> searchFileLikeMatch(folderName,pattern);
                if(v.size() == 0){
                    cout<<"No file contains the given name"<<endl;
                }
                else{
                    cout<<"Matched files :" <<endl;
                    for(string i : v){
                        cout<<i<<endl;
                    }
                    cout<<endl;
                }

            }

        }
        else if(input == 5){
            cout<<endl;
            cout<<"Exited the system successfully"<<endl;
            cout<<endl;
            break;
        }

    }
    
    return 0;
}