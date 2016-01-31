/*
 * Copyright (c) 2013-2014, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Patent rights are not granted under this agreement. Patent rights are
 *       available under FRAND terms.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL XEROX or PARC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * @file config_Forwarder_Local.h
 * @brief Generates stack and connection configuration information
 *
 * Each component in the protocol stack must have a configuration element.
 * This module generates the configuration elements for the local testing forwarder.
 *
 * The local forwarder requires one parameter for the path to the unix socket.
 *
 * @code
 * {
 *      // Configure a stack with {APIConnector,TLVCodec,LocalForwarder}
 *
 *      stackConfig = ccnxStackConfig_Create();
 *      connConfig = ccnxConnectionConfig_Create();
 *
 *      apiConnector_ProtocolStackConfig(stackConfig);
 *      apiConnector_ConnectionConfig(connConfig);
 *      tlvCodec_ProtocolStackConfig(stackConfig);
 *      tlvCodec_ConnectionConfig(connConfig);
 *      localForwarder_ProtocolStackConfig(stackConfig);
 *      localForwarder_ConnectionConfig(connConfig, "/var/run/bentpipe.sock");
 *
 *      CCNxTransportConfig *config = ccnxTransportConfig_Create(stackConfig, connConfig);
 * }
 *
 * @author Marc Mosko, Palo Alto Research Center (Xerox PARC)
 * @copyright 2013-2014, Xerox Corporation (Xerox)and Palo Alto Research Center (PARC).  All rights reserved.
 */

#ifndef Libccnx_config_Forwarder_Local_h
#define Libccnx_config_Forwarder_Local_h

#include <ccnx/transport/common/ccnx_TransportConfig.h>

/**
 * Generates the configuration settings included in the Protocol Stack configuration
 *
 * Adds configuration elements to the Protocol Stack configuration
 *
 * { "FWD_LOCAL" : {  } }
 *
 * @param [in] stackConfig The protocl stack configuration to update
 *
 * @return non-null The updated protocol stack configuration
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
CCNxStackConfig *localForwarder_ProtocolStackConfig(CCNxStackConfig *stackConfig);

/**
 * Generates:
 *
 */

/**
 * Generates the configuration settings included in the Connection configuration
 *
 * Adds configuration elements to the `CCNxConnectionConfig`
 *
 *  { "FWD_LOCAL" : { "path" : pipePath } }
 *
 * @param [in] config A pointer to a valid CCNxConnectionConfig instance.
 * @param [in] pipePath The filesystem path to the unix domain socket
 *
 * @return non-null The modified `CCNxConnectionConfig`
 *
 * Example:
 * @code
 * <#example#>
 * @endcode
 */
CCNxConnectionConfig *localForwarder_ConnectionConfig(CCNxConnectionConfig *config, const char *pipePath);

/**
 * Returns the text string for this component
 *
 * Used as the text key to a JSON block.  You do not need to free it.
 *
 * @return non-null A text string unique to this component
 *
 */
const char *localForwarder_GetName(void);

const char *localForwarder_GetPath(PARCJSON *connectionJson);
#endif // Libccnx_config_Forwarder_Local_h