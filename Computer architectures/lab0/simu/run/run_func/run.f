+incdir+../../../rtl/TOP
+incdir+../../../rtl/CPU
+incdir+../../../rtl/URT
+incdir+../../../rtl/SPI
+incdir+../../../rtl/MIG
+incdir+../../../rtl/MAC
+incdir+../../../rtl/AMBA
+incdir+../../../rtl/CONFREG
+incdir+../../testbench
+loadpli1=debpli.so:deb_PLIPtr
+nclog_ncsim+ncsim.log
+access+rw
-sv
-nowarn MRSTAR
+pathpulse
+profile
+define+_DUMPDUMP
-f sys.list
-f rtl.list
-f lib.list
