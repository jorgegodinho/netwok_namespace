cmake_minimum_required(VERSION 3.22)
project(network_namespaces C)

set(CMAKE_C_STANDARD 99)

add_executable(network_namespaces main.c scripts/create_namespace/create_namespace.c scripts/create_namespace/create_namespace.h scripts/enable_lo/enable_lo.c scripts/enable_lo/enable_lo.h scripts/create_veth/create_veth.c scripts/create_veth/create_veth.h scripts/link_veth/link_veth.c scripts/link_veth/link_veth.h scripts/assign_ip/add_address.c scripts/assign_ip/add_address.h scripts/enable_veth/enable_veth.c scripts/enable_veth/enable_veth.h scripts/unshare/unshare.c scripts/unshare/unshare.h scripts/set_namespace/set_namespace.c scripts/set_namespace/set_namespace.h applications/entrypoint.c applications/entrypoint.h applications/container.c applications/container.h scripts/open_port/open_port.c scripts/open_port/open_port.h scripts/set_default_gateway/set_default_gateway.c scripts/set_default_gateway/set_default_gateway.h)
