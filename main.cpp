#include"mostar.h"

using namespace std;

void File_type(char type);
void File_mode(int mode);

int main(int argc, char *argv[]) 
{
	int Tar_Size = 0;

	Tar_Size = Cal_Size(argv[1]);	
	if(Tar_Size > 0) Tar_Data(Tar_Size, argv[1]);

	return 0;
}
