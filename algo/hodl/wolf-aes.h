#ifndef __WOLF_AES_H
#define __WOLF_AES_H

#include <stdint.h>
#include <x86intrin.h>

#define AES_PARALLEL_N 8
#define BLOCK_COUNT 256

void ExpandAESKey256(__m128i *keys, const __m128i *KeyBuf);
void AES256CBC(__m128i** data, const __m128i** next, __m128i ExpandedKey[][16], __m128i* IV);

#endif		// __WOLF_AES_H
