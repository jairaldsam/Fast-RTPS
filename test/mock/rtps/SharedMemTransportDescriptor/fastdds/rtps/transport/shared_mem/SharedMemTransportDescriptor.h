// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _FASTDDS_SHAREDMEM_TRANSPORT_DESCRIPTOR_
#define _FASTDDS_SHAREDMEM_TRANSPORT_DESCRIPTOR_

#include "fastdds/rtps/transport/TransportDescriptorInterface.h"

namespace eprosima {
namespace fastdds {
namespace rtps {

class TransportInterface;

/**
 * Shared memory transport configuration
 *
 * @ingroup TRANSPORT_MODULE
 */
typedef struct SharedMemTransportDescriptor : public TransportDescriptorInterface
{
    virtual ~SharedMemTransportDescriptor() {}


    RTPS_DllAPI SharedMemTransportDescriptor()
        : TransportDescriptorInterface(0, 0)
    {

    }

    RTPS_DllAPI SharedMemTransportDescriptor(
            const SharedMemTransportDescriptor& t)
        : TransportDescriptorInterface(t)
    {
        (void)t;
    }

	TransportInterface* create_transport() const override
	{
		return nullptr;
	}

    uint32_t min_send_buffer_size() const override {return 0;}

    uint32_t segment_size;
    uint32_t port_queue_capacity;

    enum class OverflowPolicy { DISCARD, FAIL };

    OverflowPolicy port_overflow_policy;
    OverflowPolicy segment_overflow_policy;
    uint32_t healthy_check_timeout_ms;
}SharedMemTransportDescriptor;

} // namespace rtps
} // namespace fastdds
} // namespace eprosima

#endif // _FASTDDS_SHAREDMEM_TRANSPORT_DESCRIPTOR_
