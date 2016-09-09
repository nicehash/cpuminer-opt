#ifndef __WOLF_AES_H
#define __WOLF_AES_H

#include <stdint.h>
#include <x86intrin.h>

void ExpandAESKey256(__m128i *keys, const __m128i *KeyBuf);
void AES256CBC(__m128i *Ciphertext, const __m128i *Plaintext, const __m128i *ExpandedKey, __m128i IV, uint32_t BlockCount);

#endif		// __WOLF_AES_H
