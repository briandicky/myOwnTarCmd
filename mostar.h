struct TarHeader 
{
	char filename[100];
	char filemode[8];
	char userid[8];
	char groupid[8];
	char filesize[12];
	char mtime[12];
	char checksum[8];
	char type;
	char lname[100];

	/* USTAR Section */
	char USTAR_id[6];
	char USTAR_ver[2];
	char username[32];
	char groupname[32];
	char devmajor[8];
	char devminor[8];
	char prefix[155];
	char pad[12];
};

class TarHeader_class 
{
	public:
		TarHeader header;
		void File_type(char type);
		void File_mode(int filemode);

};

int Cal_Size(char filename[]);

void Tar_Data(int Tar_Size, char filename[]);
