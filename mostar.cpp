#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#include "mostar.h"

using namespace std;

void File_type(char type) 
{
	switch(type) {
		case '1': cout << "l"; break;
		case '2': cout << "l"; break;
		case '3': cout << "c"; break;
		case '4': cout << "b"; break;
		case '5': cout << "d"; break;
		case '6': cout << "p"; break;
		default: cout << "-"; break;
	}
}

void File_mode(int filemode) 
{
	for(int i = 2; i >= 0; i--) {
		int mode = 0;
		mode = filemode / pow(10, i);
		filemode -= mode * pow(10, i);
		
		if(mode >> 2 & 1) cout << "r";
		else cout << "-";
		
		if(mode >> 1 & 1) cout << "w";
		else cout << "-";
		
		if(mode & 1) cout << "x";
		else cout << "-";
	}
}

int Cal_Size(char filename[]) 
{
	ifstream fs;
	TarHeader_class miii;

	int Tar_Size = 0;
	int File_num = 0;

	fs.open(filename);

	if( fs.is_open() ) {
		fs.seekg(0, fs.end);
		Tar_Size = fs.tellg();
		fs.seekg(0, fs.beg);
		
		while(Tar_Size > 0) {
    		fs.read((char*)&miii.header, 512);
    	    Tar_Size -= 512;
    	 
		 	if(strncmp(miii.header.USTAR_id, "ustar", 5) != 0) {
				if(!strcmp(miii.header.filename, "") && !strcmp(miii.header.filesize, "")) {
					Tar_Size = fs.tellg();
					Tar_Size -= 512;
					break;
				}
    	    	cout << "Not a ustar file." << endl
    	    		 << "File opening error." << endl;
    	    	fs.close();	    	
				return -1;
    	    }

			File_num++;
			int size = 0;
    	  	size = strtol(miii.header.filesize, NULL, 8);
			int shift = 0;
			shift += size / 512;
			
			if(size % 512 > 0) shift++;
			
			fs.seekg(512 * shift, fs.cur);
			Tar_Size -= shift * 512;
		}
	}
	else {
		cout << "File opening error." << endl;
		fs.close();
		return -1;
	}

	fs.close();
	cout << "total " << File_num << " file(s)" << endl;

	return Tar_Size;
}

void Tar_Data(int Tar_Size, char filename[]) 
{
	ifstream fs;
	TarHeader_class miii;
	fs.open(filename);

	if(fs.is_open()) {
		while(Tar_Size > 0) {
     	   	fs.read((char*)&miii.header, 512);
           	Tar_Size -= 512;
   			File_type(miii.header.type);
     		File_mode(atoi(miii.header.filemode));
     	   	
			cout << setw(10) << miii.header.username
				 << setw(16) << miii.header.groupname;
       		
			int size = 0;
        	size = strtol(miii.header.filesize, NULL, 8);
        	cout << setw(16) << size << " " << miii.header.filename << endl;
			
			int shift = 0;
			shift += size / 512;
			
			if(size % 512 > 0) shift++;
		
			fs.seekg(512 * shift, fs.cur);
			Tar_Size -= shift * 512;
		}
	}
}
