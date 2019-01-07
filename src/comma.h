// Copyright (c) 2019 Daniel Lovasko
// All Rights Reserved
//
// Distributed under the terms of the 2-clause BSD License. The full
// license is in the file LICENSE, distributed as part of this software.

#ifndef LIBCOMMA_H
#define LIBCOMMA_H

#include <stdint.h>
#include <stddef.h>


// Integer types.
#define COMMA_INT_U8  1 ///< 8-bit unsigned.
#define COMMA_INT_U16 2 ///< 16-bit unsigned.
#define COMMA_INT_U32 3 ///< 32-bit unsigned.
#define COMMA_INT_U64 4 ///< 64-bit unsigned.
#define COMMA_INT_I8  5 ///< 8-bit signed.
#define COMMA_INT_I16 6 ///< 16-bit signed.
#define COMMA_INT_I32 7 ///< 32-bit signed.
#define COMMA_INT_I64 8 ///< 64-bit signed.

// Float types.
#define COMMA_FLT_SINGLE 1 ///< 32-bit floating-point decimal.
#define COMMA_FLT_DOUBLE 2 ///< 64-bit floating-point decimal.

// Network address types.
#define COMMA_NET_IP4 1 ///< IPv4 address.
#define COMMA_NET_IP6 2 ///< IPv6 address.
#define COMMA_NET_MAC 3 ///< MAC address.
#define COMMA_NET_IPX 4 ///< IPv4 or IPv6 address.


/// Add a fixed-size string to the record.
int8_t comma_str(struct comma* file, const char* name, const size_t smax);

/// Add an integer number to the record.
int8_t comma_int(struct comma* file, const char* name, const uint8_t ifmt);

/// Add a floating-point number to the record.
int8_t comma_flt(struct comma* file, const char* name, const uint8_t ffmt);

/// Add a network address to the record.
int8_t comma_net(struct comma* file, const char* name, const uint8_t nfmt);

/// Skip a selected number of bytes in the record.
int8_t comma_pad(struct comma* file, const char* name, const size_t pad);

/// Reset the record format and its parsing.
int8_t comma_rst(struct comma* file);

/// Parse a single record from a string.
int8_t comma_get(struct comma* file,
                 const char* str,
                 const size_t slen,
                 void* data,
                 const size_t dlen);

/// Produce a single record into a string.
int8_t comma_put(struct comma* file,
                 const void* data,
                 const size_t dlen,
                 char* str,
                 const size_t slen);

/// Convert an error code into English description.
void comma_err(struct comma* file, const int8_t code, const char** estr);

#endif
