
if WANT_JANSSON
JANSSON_INCLUDES= -I$(top_srcdir)/compat/jansson
else
JANSSON_INCLUDES=
endif

EXTRA_DIST	= example-cfg.json nomacro.pl

SUBDIRS		= compat

ALL_INCLUDES	= @PTHREAD_FLAGS@ -fno-strict-aliasing $(JANSSON_INCLUDES) -I.

bin_PROGRAMS	= cpuminer

dist_man_MANS	= cpuminer.1

cpuminer_SOURCES = \
  cpu-miner.c \
  util.c \
  uint256.cpp \
  api.c \
  sysinfos.c \
  algo-gate-api.c\
  algo/groestl/sph_groestl.c \
  algo/skein/sph_skein.c \
  algo/bmw/sph_bmw.c \
  algo/shavite/sph_shavite.c \
  algo/shavite/shavite.c \
  algo/echo/sph_echo.c \
  algo/blake/sph_blake.c \
  algo/heavy/sph_hefty1.c \
  algo/blake/mod_blakecoin.c \
  algo/luffa/sph_luffa.c \
  algo/cubehash/sph_cubehash.c \
  algo/simd/sph_simd.c \
  algo/hamsi/sph_hamsi.c \
  algo/fugue/sph_fugue.c \
  algo/gost/sph_gost.c \
  algo/jh/sph_jh.c \
  algo/keccak/sph_keccak.c \
  algo/keccak/keccak.c\
  algo/sha3/sph_sha2.c \
  algo/sha3/sph_sha2big.c \
  algo/shabal/sph_shabal.c \
  algo/whirlpool/sph_whirlpool.c\
  crypto/blake2s.c \
  crypto/oaes_lib.c \
  crypto/c_keccak.c \
  crypto/c_groestl.c \
  crypto/c_blake256.c \
  crypto/c_jh.c \
  crypto/c_skein.c \
  crypto/hash.c \
  crypto/aesb.c \
  crypto/magimath.cpp \
  algo/axiom.c \
  algo/cryptonight/cryptonight-common.c\
  algo/cryptonight/cryptonight-aesni.c\
  algo/cryptonight/cryptonight.c\
  algo/groestl/aes_ni/hash-groestl.c \
  algo/groestl/aes_ni/hash-groestl256.c \
  algo/hodl/hodl.cpp \
  algo/hodl/hodl-gate.c \
  algo/hodl/hodl_arith_uint256.cpp \
  algo/hodl/hodl_uint256.cpp \
  algo/hodl/hash.cpp \
  algo/hodl/hmac_sha512.cpp \
  algo/hodl/sha256.cpp \
  algo/hodl/sha512.cpp \
  algo/hodl/utilstrencodings.cpp \
  algo/hodl/hodl-wolf.c \
  algo/hodl/aes.c \
  algo/hodl/sha512_avx.c \
  algo/hodl/sha512_avx2.c \
  algo/lyra2/lyra2.c \
  algo/lyra2/sponge.c \
  algo/lyra2/lyra2re.c \
  algo/scryptjane/scrypt-jane.c \
  algo/sha2/sha2.c


disable_flags =

if USE_ASM
   cpuminer_SOURCES += asm/neoscrypt_asm.S
if ARCH_x86
   cpuminer_SOURCES += asm/sha2-x86.S asm/scrypt-x86.S asm/aesb-x86.S
endif
if ARCH_x86_64
   cpuminer_SOURCES += asm/sha2-x64.S asm/scrypt-x64.S asm/aesb-x64.S
endif
if ARCH_ARM
   cpuminer_SOURCES += asm/sha2-arm.S asm/scrypt-arm.S
endif
else
   disable_flags += -DNOASM
endif

if HAVE_WINDOWS
   cpuminer_SOURCES += compat/winansi.c
endif

cpuminer_LDFLAGS	= @LDFLAGS@
cpuminer_LDADD	= @LIBCURL@ @JANSSON_LIBS@ @PTHREAD_LIBS@ @WS2_LIBS@ -lssl -lcrypto -lgmp
cpuminer_CPPFLAGS = @LIBCURL_CPPFLAGS@ $(ALL_INCLUDES)
cpuminer_CFLAGS   = -Wno-pointer-sign -Wno-pointer-to-int-cast $(disable_flags)

if HAVE_WINDOWS
cpuminer_CFLAGS += -Wl,--stack,10485760
endif

if HAVE_WINDOWS
# use to profile an object
# gprof_cflags = -pg -g3
# cpuminer_LDFLAGS += -pg
# cpuminer_CFLAGS += -fno-inline-functions -static

# copy/paste from generated Makefile
common_ccflags = $(DEFS) $(ALL_INCLUDES) $(cpuminer_CPPFLAGS) $(CPPFLAGS) $(cpuminer_CFLAGS) $(CFLAGS)

# special CFLAGS (if you find a simpler way to do that tell me ;)
cpuminer-neoscrypt.o: neoscrypt.c
	@echo "CUSTOM ${@}: ${filter %.o,${^}} ${filter %.c,${^}}"
	$(CC) $(common_ccflags) -g -O3 $(gprof_cflags) -MT $@ -MD -MP -c -o $@ $<


endif
