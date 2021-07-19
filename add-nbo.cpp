#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	FILE *thousand = fopen(argv[1], "rb");
	FILE *five_hundred = fopen(argv[2], "rb");
	
	uint32_t tho, five;
	fread(&tho, sizeof(tho), 1, thousand);
	fread(&five, sizeof(five), 1, five_hundred);

	uint32_t sum = ntohl(tho) + ntohl(five);

	printf("\n%d(0x%x) + %d(0x%x) = %d(0x%x)", ntohl(tho), ntohl(tho), ntohl(five), ntohl(five), sum, sum);

	fclose(thousand);
	fclose(five_hundred);
}

