all: compile

compile: main.c server/server.c scripts/create_namespace/create_namespace.c scripts/enable_lo/enable_lo.c scripts/create_veth/create_veth.c scripts/link_veth/link_veth.c scripts/add_address/add_address.c scripts/enable_veth/enable_veth.c scripts/set_namespace/set_namespace.c applications/entrypoint.c applications/container.c scripts/set_default_gateway/set_default_gateway.c
	gcc -o network_namespaces main.c server/server.c server/server.h scripts/create_namespace/create_namespace.c scripts/create_namespace/create_namespace.h scripts/enable_lo/enable_lo.c scripts/enable_lo/enable_lo.h scripts/create_veth/create_veth.c scripts/create_veth/create_veth.h scripts/link_veth/link_veth.c scripts/link_veth/link_veth.h scripts/add_address/add_address.c scripts/add_address/add_address.h scripts/enable_veth/enable_veth.c scripts/enable_veth/enable_veth.h scripts/set_namespace/set_namespace.c scripts/set_namespace/set_namespace.h applications/entrypoint.c applications/entrypoint.h applications/container.c applications/container.h scripts/set_default_gateway/set_default_gateway.c scripts/set_default_gateway/set_default_gateway.h

clean:
	rm network_namespaces