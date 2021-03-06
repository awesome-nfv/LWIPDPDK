#ifndef _DPDK_H
#define _DPDK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/queue.h>
#include <setjmp.h>
#include <stdarg.h>
#include <errno.h>
#include <getopt.h>

#include <rte_common.h>
#include <rte_byteorder.h>
#include <rte_log.h>
#include <rte_memory.h>
#include <rte_memcpy.h>
#include <rte_memzone.h>
#include <rte_tailq.h>
#include <rte_eal.h>
#include <rte_per_lcore.h>
#include <rte_launch.h>
#include <rte_atomic.h>
#include <rte_cycles.h>
#include <rte_prefetch.h>
#include <rte_lcore.h>
#include <rte_per_lcore.h>
#include <rte_branch_prediction.h>
#include <rte_interrupts.h>
#include <rte_pci.h>
#include <rte_random.h>
#include <rte_debug.h>
#include <rte_ether.h>
#include <rte_ethdev.h>
#include <rte_ring.h>
#include <rte_mempool.h>
#include <rte_mbuf.h>
#include <rte_ip.h>
#include <rte_string_fns.h>


#define RX_PTHRESH 8
#define RX_HTHRESH 8
#define RX_WTHRESH 4
#define RTE_TEST_RX_DESC_DEFAULT 128

#define TX_PTHRESH 36
#define TX_HTHRESH 0
#define TX_WTHRESH 0
#define RTE_TEST_TX_DESC_DEFAULT 512

#define NUM_PORTS 1
#define NUM_TX_QUEUES_PER_LCORE NUM_PORTS
#define NUM_RX_QUEUES_PER_LCORE 1
#define NB_SOCKETS 2
#define MAX_PKT_BURST 32 /*INDIVIDUAL CACHE SIZE OF EACH CORE - can be changed*/
#define START_CORE 0
#define NUM_LCORE 1 

#define NB_MBUF 8192
#define MBUF_SIZE (2048 + sizeof(struct rte_mbuf) + RTE_PKTMBUF_HEADROOM)

struct mbuf_table {
	uint16_t len;
	struct rte_mbuf *m_table[MAX_PKT_BURST];
} __rte_cache_aligned;

struct lcore_conf {
	uint16_t n_rx_queue;
	uint8_t rx_queue_id;
	uint8_t rx_port_id;
	uint8_t tx_queue_id;
	uint8_t tx_port_id;
	struct mbuf_table tx_mbufs;
} __rte_cache_aligned;

int lcore_setup(void);
int init_dpdk(int, char**);
err_t dpdk_device_init(struct netif* );
err_t dpdk_input(struct rte_mbuf*, struct netif*);
err_t dpdk_output(struct netif*, struct pbuf*);
void send_burst(struct lcore_conf*, uint16_t, uint8_t);
int init_mem(void);
__attribute__((noreturn)) int dpdk_driver(__attribute__((unused)) void *);
#endif
