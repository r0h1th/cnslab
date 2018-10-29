#include<iostream>
#include "blowfish.h"
#include<string.h>

#define BLOWFISH_F(x) \
	(((ctx->sbox[0][x >> 24] + ctx->sbox[1][(x >> 16) & 0xFF]) \
	^ ctx->sbox[2][(x >> 8) & 0xFF]) + ctx->sbox[3][x & 0xFF])

void blowfish_encryptblock(blowfish_context_t *ctx, unsigned int *hi, unsigned int *lo)
{
	printf("Encryption\n");
	int i, temp;

	for(i = 0; i < 16; i++) {
		*hi ^= ctx->pbox[i];
		*lo ^= BLOWFISH_F(*hi);
		temp = *hi, *hi = *lo, *lo = temp;
		printf("round:%d  key:%x   hi:%x  lo:%x\n",i+1,ctx->pbox[i],*hi,*lo);
	}
	temp = *hi, *hi = *lo, *lo = temp;

	*lo ^= ctx->pbox[16];
	*hi ^= ctx->pbox[17];
	printf("round:%d  hi:%x  lo:%x\n",17,*hi,*lo);
}

void blowfish_decryptblock(blowfish_context_t *ctx, unsigned int *hi, unsigned int *lo)
{
	int i, temp;
	
	printf("Decryption:\n");
	
	for(i = 17; i > 1; i--) {
		*hi ^= ctx->pbox[i];
		*lo ^= BLOWFISH_F(*hi);
		temp = *hi, *hi = *lo, *lo = temp;
		printf("round:%d  key:%x   hi:%x  lo:%x\n",i,ctx->pbox[i],*hi,*lo);
	}
	temp = *hi, *hi = *lo, *lo = temp;

	*lo ^= ctx->pbox[1];
	*hi ^= ctx->pbox[0];
	printf("round:%d  hi:%x  lo:%x\n",1,*hi,*lo);
}

int blowfish_initiate(blowfish_context_t *ctx, unsigned char *key, int keybytes)
{
	if(keybytes > 56)
		return -1;

	int i, j, k;
	unsigned int calc;

	for(i = 0; i < 4; i++)
		memcpy(ctx->sbox[i], ORIG_S[i], 256 * sizeof(unsigned int));

	memcpy(ctx->pbox, ORIG_P, 18 * sizeof(unsigned int));

	if(keybytes) {
		for(i = 0, j = 0; i < 18; i++) {
			for(k = 0, calc = 0; k < 4; k++) {
				calc <<= 8, calc |= key[j++];
				if(j == keybytes)
					j = 0;
			}
			ctx->pbox[i] ^= calc;
		}
	}

	unsigned int hi = 0, lo = 0;

	for(i = 0; i < 18; i += 2) {
		blowfish_encryptblock(ctx, &hi, &lo);
		ctx->pbox[i] = hi;
		ctx->pbox[i + 1] = lo;
	}

	for(i = 0; i < 4; i++) {
		for(j = 0; j < 256; j += 2) {
			blowfish_encryptblock(ctx, &hi, &lo);
			ctx->sbox[i][j] = hi;
			ctx->sbox[i][j + 1] = lo;
		}
	}

	return 0;
}

void blowfish_clean(blowfish_context_t *ctx)
{
	memset(ctx, 0, sizeof(blowfish_context_t));
}


unsigned int get_hi(char *pt){
	
			unsigned int val=0;
	
	for(int i=0;i<4;i++){
		
		 char t=pt[i];
		
		val=val|(t<<(24-8*i));
		
	}
	
	return val;	

	
}

unsigned int get_lo(char *pt){
	
		unsigned int val=0;
	
	for(int i=4;i<8;i++){
		
		 char t=pt[i];
		
		val=val|(t<<(24-8*i));
		
	}
	
	return val;	
	
}

void print_text(int a){
	
	for(int i=0;i<4;i++){
		
			 char c= (a>>8*(3-i))&(0x000000FF);
			printf("%c",c);
	}
	
}

#ifdef TESTING
int main(int argc, char *argv[])
{
	char pt[9];
	puts("Blowfish testing function...");
	blowfish_context_t *ctx = (blowfish_context_t *)malloc(sizeof(blowfish_context_t));
	if(!ctx) {
		puts("Could not allocate enough memory!");
		return -1;
	}
	if(blowfish_initiate(ctx, (unsigned char *)"TESTKEY", 7) == 0) {
		puts("Keys initiated");
		scanf("%s",pt);
		
		unsigned int hi , lo ;
		hi=get_hi(pt);
		lo=get_lo(pt);
		blowfish_encryptblock(ctx, &hi, &lo);
		//printf("Encoded: %08X %08X\n", hi, lo);
		/*if((hi == 0xDF333FD2) && (lo == 0x30A71BB4))
			puts("Encryption Test Passed");
		else puts("Encryption Test Failed");*/
		
		printf("After encryption cipher in hexa: %x%x\n",hi,lo);
		
		
		blowfish_decryptblock(ctx, &hi, &lo);
		//if((hi == 1) && (lo == 2))
		//	puts("Decryption Test Passed");
		//else puts("Decryption Test Failed");
		
		print_text(hi);
		print_text(lo);
		printf("\n");
		
	}else puts("Error initiating keys");
	puts("Done!");
	blowfish_clean(ctx);
	free(ctx);
	return 0;
}
#endif

