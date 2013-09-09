LWIPDPDK
========


1) DPDK - not modified from original

   Installation instructions and source files can be downloaded at dpdk.org/download or
   
   For UBC Computer Science: 1) its located in ~/dpdk-1.2.3r2 of hs6
                             2) the ping echo example is in ~/dpdk-1.2.3r2/examples/ping_echo 
                             3) NUMA needs to be turned on in BIOS 
			     4) There are setup scripts made by DPDK in ~/dpdk-1.2.3r2/tools (setup.sh)  and in ~/ (mount_huge)
   
2) LWIP - will be modified from original

   The source code for LWIP and modifications come with the repository
   
   LWIP comes with just the source which you can download at savannah.nongnu.org/git/?group=lwip

   Apps that use LWIP can be downloaded at download.savannah.gnu.org/releases/lwip/ which contains source code for apps (http servers, sockets, ... etc) while the system files are in ports (the three ports for unix systems are under /ports/unix/proj)

   For UBC Computer Science: 1) it is located in ~/DPDK-LWIP 
		             2) the src code is in lwip/
			     3) the application is in contrib-1.4.1/apps
			     4) the system-specific port contrib-1.4.1/ports


3) Putting a TCP/IP Stack on DPDK

   LWIP is compiled as a library in lwiplib/
  
   DPDK is compiled using the dpdk app makefiles with some modifications is in dpdk_app/ (the source codes are here). The http_server.c is the start of the program. 
