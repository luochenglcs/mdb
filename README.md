# mdb

------

This is a Module debug tool of the Solaris to other popular operating systems, such as Linux systems.



## Warning!

------

Now,  it only just can use correctly dcmds commands related to libumem memory management, and there are many HACKs in the code.



## Dependencies

------

```c
byacc
ncurses-devel
efiutil-libefl-devel
libbsd-devel
flex
libumem-devel
```



## Compiling and installing

------

```c
cd mdb/common
make all
make install
```



## Examples

------

1. Start one process with LD_PRELOAD=/usr/lib64/libumem.so.0

   ```c
   //examples: start numad
   LD_PRELOAD=/usr/lib64/libumem.so.0 numad
   ```

2. mdb attach target process

   ```c
   //mdb -p target_pid
   [root@localhost mdb]# mdb -p `pidof numad`
   loading modules: [ libdl-2.28.so libc-2.28.so libm-2.28.so librt-2.28.so libpthread-2.28.so libumem.so.0.0.0 ld-2.28.so ]
   ```

3. use libumem releate dcmds to view memory info

   ```c
   ::dcmds
     ...
   umalog                   - display umem transaction log and stack traces
   umastat                  - umem allocator stats
   umausers                 - display current medium and large users of the umem allocator
   umem_cache               - print a umem cache
   umem_debug               - toggle umem dcmd/walk debugging
   umem_log                 - dump umem transaction log
   umem_malloc_dist         - report distribution of outstanding malloc()s
   umem_malloc_info         - report information about malloc()s by cache
   umem_status              - Print umem status and message buffer
   umem_verify              - check integrity of umem-managed memory
   unload                   - unload debugger module
   unset                    - unset variables
   unsetenv                 - clear an environment variable
   vars                     - print listing of variables
   version                  - print debugger version string
   vmem                     - print a vmem_t
   vmem_seg                 - print or filter a vmem_seg
   vtop                     - print physical mapping of virtual address
   ....
   ```

   ```c
   ::findleaks  //use findleaks dcmds
   BYTES             LEAKED         VMEM_SEG CALLER
   8388608                7     7fc4c74c3000 MMAP
   4096                   1     7fc4c8e90000 MMAP
   8192                   1     7fc4c8e8c000 MMAP
   20480                  1     7fc4c8e71000 MMAP
   53248                  1     7fc4c8c59000 MMAP
   16384                  1     7fc4c8a30000 MMAP
   16384                  1     7fc4c8285000 MMAP
   ------------------------------------------------------------------------
              Total       7 oversized leaks, 8507392 bytes
   
   CACHE             LEAKED           BUFFER CALLER
   00007fc4c8e644c8       1 00007fc4c8e32000 ?
   00007fc4c8e67948       1 00007fc4c8e31540 ?
   00007fc4c8e684c8       1 00007fc4c8e35b40 ?
   00007fc4c8e6a048       2 00007fc4c8e60c00 ?
   00007fc4c8e6b048       1 00007fc4c8e5de00 ?
   00007fc4c8e6b4c8       1 00007fc4c8e5edc0 ?
   00007fc4c8e6f4c8       1 00007fc4c8e5bf60 ?
   00007fc4c8e70048       4 00007fc4c8e5af80 ?
   00007fc4c8e704c8       4 00007fc4c8e5ff40 ?
   00007fc4c8e70948       6 00007fc4c8e62ea0 ?
   ------------------------------------------------------------------------
              Total      22 buffers, 14320 bytes
   ```

   ```c
   ::umem_cache	
   ADDR             NAME                      FLAG    CFLAG  BUFSIZE  BUFTOTL
   00007fa35a8de048 umem_magazine_1           0000 80080000       16      252
   00007fa35a8de4c8 umem_magazine_3           0000 80080000       32      126
   00007fa35a8de948 umem_magazine_7           0000 80080000       64       63
   00007fa35a8dd048 umem_magazine_15          0000 80080000      128       31
   00007fa35a8dd4c8 umem_magazine_31          0000 80080000      256        0
   00007fa35a8dd948 umem_magazine_47          0000 80080000      384        0
   00007fa35a8dc048 umem_magazine_63          0000 80080000      512        0
   00007fa35a8dc4c8 umem_magazine_95          0000 80080000      768        0
   00007fa35a8dc948 umem_magazine_143         0000 80080000     1152        0
   00007fa35a8db048 umem_slab_cache           0000 80080000       56       63
   00007fa35a8db4c8 umem_bufctl_cache         0000 80080000       24      126
   00007fa35a8db948 umem_bufctl_audit_cache   0000 80080000      192        0
   00007fa35a8d8048 umem_va_4096              0200 00110000     4096       32
   00007fa35a8d84c8 umem_va_8192              0200 00110000     8192       16
   00007fa35a8d8948 umem_va_12288             0200 00110000    12288        0
   00007fa35a8d6048 umem_va_16384             0200 00110000    16384        0
   00007fa35a8d64c8 umem_va_20480             0200 00110000    20480        0
   00007fa35a8d6948 umem_va_24576             0200 00110000    24576        0
   00007fa35a8d5048 umem_va_28672             0200 00110000    28672        0
   00007fa35a8d54c8 umem_va_32768             0200 00110000    32768        0
   00007fa35a8d5948 umem_alloc_8              0000 80000000        8        0
   00007fa35a8cd048 umem_alloc_16             0000 80000000       16      252
   00007fa35a8cd4c8 umem_alloc_32             0000 80000000       32      126
   00007fa35a8cd948 umem_alloc_48             0000 80000000       48       84
   00007fa35a8cc048 umem_alloc_64             0000 80000000       64       63
   00007fa35a8cc4c8 umem_alloc_80             0000 80000000       80       50
   00007fa35a8cc948 umem_alloc_96             0000 80000000       96       42
   00007fa35a8cb048 umem_alloc_112            0000 80000000      112        0
   00007fa35a8cb4c8 umem_alloc_128            0000 80000000      128        0
   00007fa35a8cb948 umem_alloc_160            0000 80000000      160        0
   00007fa35a8ca048 umem_alloc_192            0000 80000000      192        0
   00007fa35a8ca4c8 umem_alloc_224            0000 80000000      224        0
   00007fa35a8ca948 umem_alloc_256            0000 80000000      256        0
   00007fa35a8c8048 umem_alloc_320            0000 80000000      320       12
   00007fa35a8c84c8 umem_alloc_384            0000 80000000      384       10
   00007fa35a8c8948 umem_alloc_448            0000 80000000      448        0
   00007fa35a8c7048 umem_alloc_512            0200 80000000      512        8
   00007fa35a8c74c8 umem_alloc_640            0200 80000000      640        0
   00007fa35a8c7948 umem_alloc_768            0200 80000000      768        0
   00007fa35a8c5048 umem_alloc_896            0200 80000000      896        0
   00007fa35a8c54c8 umem_alloc_1152           0200 80000000     1152        7
   00007fa35a8c5948 umem_alloc_1344           0200 80000000     1344        0
   00007fa35a8c4048 umem_alloc_1600           0200 80000000     1600        0
   00007fa35a8c44c8 umem_alloc_2048           0200 80000000     2048        0
   00007fa35a8c4948 umem_alloc_2688           0200 80000000     2688        3
   00007fa35a8c1048 umem_alloc_4096           0200 80000000     4096        0
   00007fa35a8c14c8 umem_alloc_8192           0200 80000000     8192        1
   00007fa35a8c1948 umem_alloc_12288          0200 80000000    12288        0
   00007fa35a8c0048 umem_alloc_16384          0200 80000000    16384        0
   ```

   ```c
   ::umem_malloc_dist
   malloc size  ------------------ Distribution ------------------ count
             0 |                                                   0
             1 |@@                                                 1
             2 |                                                   0
             3 |                                                   0
             4 |                                                   0
             5 |                                                   0
             6 |                                                   0
             7 |                                                   0
             8 |@@@@@@                                             3
     ...
   ```

   more dcmds ...

4. quit mdb attach

   ```
   ::quit
   ```



## License

------


The  mdb is licensed under Sun's/Oracle's CDDL license. Original copyrights are left intact. No GPL code is incorporated into the release, to avoid legal conflicts.

Any mistakes or omissions in copyright attribution will be my mistake, so please let me know if there are such cases.

If Sun/Oracle migrate to a GPL friendly license, then this port of dmb can follow. I do not own the license or assert any rights on the licensing other than that expected of me as a consumer/supplier.

I have no political affiliation or preference for a licensing scheme, simply that Sun/Oracle has gracefully donated to the community a large body of work.

I reserve the right to change the licensing model for my own code at a later date, when and if someone puts forward a case as to the correct license agreement.

If the code is useful to you - great !. Spread it around and get people to use, debug and enhance it.
