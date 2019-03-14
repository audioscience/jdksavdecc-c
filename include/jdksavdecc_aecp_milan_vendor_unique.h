#pragma once

/*
  Copyright (c) 2019, AudioScience, Inc
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

   3. Neither the name of J.D. Koftinoff Software, Ltd. nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#include "jdksavdecc_world.h"
#include "jdksavdecc_aecp.h"

#ifdef __cplusplus
extern "C" {
#endif


/** \addtogroup aecp AECP - Clause 9 */
/*@{*/

/** \addtogroup aecp_vendor AECP Vendor
*/
/*@{*/

#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_PROTOCOL_ID                                                                        \
    {                                                                                                                          \
        {                                                                                                                      \
            0x00, 0x1b, 0xc5, 0x0a, 0xc1, 0x00                                                                                 \
        }                                                                                                                      \
    }


struct jdksavdecc_aecp_milan_vendor_unique
{
    struct jdksavdecc_aecpdu_common aecpdu_header;
    struct jdksavdecc_eui48 protocol_id;
    uint16_t command_type;
};

/** \addtogroup aecp_vendor AECP Vendor Unique Offsets - Clause 9.2.1.5 */
/*@{*/

#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_OFFSET_CONTROLLER_ENTITY_ID             ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 0 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_OFFSET_SEQUENCE_ID                      ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 8 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_OFFSET_PROTOCOL_ID                      ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 10 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_OFFSET_COMMAND_TYPE                     ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 16 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_OFFSET_COMMAND_DATA                     ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 18 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_LEN                                     ( 20 )

#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_RESPONSE_OFFSET_CONTROLLER_ENTITY_ID    ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 0 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_RESPONSE_OFFSET_SEQUENCE_ID             ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 8 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_RESPONSE_OFFSET_PROTOCOL_ID             ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 10 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_RESPONSE_OFFSET_COMMAND_TYPE            ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 16 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_RESPONSE_OFFSET_COMMAND_RESERVED        ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 18 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_RESPONSE_OFFSET_PROTOCOL_VERSION        ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 20 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_RESPONSE_OFFSET_FEATURE_FLAGS           ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 24 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_RESPONSE_OFFSET_CERTIFICATION_VERSION   ( JDKSAVDECC_COMMON_CONTROL_HEADER_LEN + 28 )
#define JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_RESPONSE_LEN                            ( 32 )


/*@}*/

/* see status returns in jdksavdecc_aecp_vendor.h file */


static inline void jdksavdecc_aecpdu_milan_vendor_unique_set_protocol_id(struct jdksavdecc_eui48  v, void *base, ssize_t pos)
{
	jdksavdecc_eui48_set(v, base, pos + JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_OFFSET_PROTOCOL_ID);
}

static inline void jdksavdecc_aecpdu_milan_vendor_unique_set_command_type(uint16_t v, void *base, ssize_t pos)
{
	jdksavdecc_uint16_set(v, base, pos + JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_OFFSET_COMMAND_TYPE);
}

static inline ssize_t jdksavdecc_aecpdu_milan_vendor_unique_write(struct jdksavdecc_aecp_milan_vendor_unique const *p, void *base, size_t pos, size_t len)
{
	ssize_t r = jdksavdecc_validate_range(pos, len, JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_LEN);
	if (r >= 0)
	{
		jdksavdecc_aecpdu_common_write(&p->aecpdu_header, base, pos, len);
		jdksavdecc_aecpdu_milan_vendor_unique_set_protocol_id(p->protocol_id, base, pos);
		jdksavdecc_aecpdu_milan_vendor_unique_set_command_type(p->command_type, base, pos);
	}
	return r;
}

static inline struct jdksavdecc_eui48 jdksavdecc_aecpdu_milan_vendor_unique_get_protocol_id(void const *base, ssize_t pos)
{
	return jdksavdecc_eui48_get(base, pos + JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_OFFSET_PROTOCOL_ID);
}

static inline uint16_t jdksavdecc_aecpdu_milan_vendor_unique_get_command_type(void const *base, ssize_t pos)
{
	return jdksavdecc_uint16_get(base, pos + JDKSAVDECC_AECP_MILAN_VENDOR_UNIQUE_OFFSET_COMMAND_TYPE);
}

static inline ssize_t jdksavdecc_aecpdu_milan_vendor_unique_read(struct jdksavdecc_aecp_milan_vendor_unique *p, void const *base, ssize_t pos, size_t len)
{
	ssize_t r = jdksavdecc_validate_range(pos, len, JDKSAVDECC_AECPDU_AEM_LEN);
	if (r >= 0)
	{
		if (jdksavdecc_aecpdu_common_read(&p->aecpdu_header, base, pos, len) >= 0)
		{
			p->protocol_id = jdksavdecc_aecpdu_milan_vendor_unique_get_protocol_id(base, pos);
			p->command_type = jdksavdecc_aecpdu_milan_vendor_unique_get_command_type(base, pos);
		}
	}
	return r;
}


/*@}*/

/*@}*/

#ifdef __cplusplus
}
#endif
