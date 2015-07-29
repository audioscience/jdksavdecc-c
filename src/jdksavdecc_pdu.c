
/*
  Copyright (c) 2013, J.D. Koftinoff Software, Ltd.
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
#include "jdksavdecc_pdu.h"

struct jdksavdecc_eui48 jdksavdecc_multicast_maap = JDKSAVDECC_MULTICAST_MAAP;

struct jdksavdecc_eui48 jdksavdecc_multicast_adp_acmp = JDKSAVDECC_MULTICAST_ADP_ACMP;

struct jdksavdecc_eui48 jdksavdecc_multicast_identification = JDKSAVDECC_MULTICAST_IDENTIFICATION;

struct jdksavdecc_eui64 jdksavdecc_identification_notification_controller_entity_id
    = JDKSAVDECC_IDENTIFICATION_NOTIFICATION_CONTROLLER_ENTITY_ID;

ssize_t jdksavdecc_common_control_header_read( struct jdksavdecc_common_control_header *p,
                                               void const *base,
                                               ssize_t pos,
                                               size_t len )
{
    ssize_t r = jdksavdecc_validate_range( pos, len, JDKSAVDECC_COMMON_CONTROL_HEADER_LEN );
    if ( r >= 0 )
    {
        p->cd = jdksavdecc_common_control_header_get_cd( base, pos );
        p->subtype = jdksavdecc_common_control_header_get_subtype( base, pos );
        p->sv = jdksavdecc_common_control_header_get_sv( base, pos );
        p->version = jdksavdecc_common_control_header_get_version( base, pos );
        p->control_data = jdksavdecc_common_control_header_get_control_data( base, pos );
        p->status = jdksavdecc_common_control_header_get_status( base, pos );
        p->control_data_length = jdksavdecc_common_control_header_get_control_data_length( base, pos );
        p->stream_id = jdksavdecc_common_control_header_get_stream_id( base, pos );
    }
    return r;
}

ssize_t jdksavdecc_common_control_header_write( struct jdksavdecc_common_control_header const *p,
                                                void *base,
                                                ssize_t pos,
                                                size_t len )
{
    ssize_t r = jdksavdecc_validate_range( pos, len, JDKSAVDECC_COMMON_CONTROL_HEADER_LEN );
    if ( r >= 0 )
    {
        jdksavdecc_common_control_header_set_cd( p->cd, base, pos );
        jdksavdecc_common_control_header_set_subtype( (uint8_t)p->subtype, base, pos );
        jdksavdecc_common_control_header_set_sv( (bool)p->sv, base, pos);
        jdksavdecc_common_control_header_set_version( (uint8_t)p->version, base, pos);
        jdksavdecc_common_control_header_set_control_data ((uint8_t)p->control_data, base, pos);
        jdksavdecc_common_control_header_set_status( (uint8_t)p->status, base, pos);
        jdksavdecc_common_control_header_set_control_data_length( (uint16_t)p->control_data_length, base, pos);
        jdksavdecc_common_control_header_set_stream_id( p->stream_id, base, pos );
    }
    return r;
}
