main:
        # 1. Set Stackpointer
        add  $r31 = $r0, 1      # initialise to 1       -> 0x000000001
        sl   $r31 = $r31, 31    # shift left by 31 bits -> 0x8000_0000
        sub  $r31 = $r31, 1     # subt$ract 1           -> 0x7fff_ffff

        # 2. Clea$r BSS
        add  $r1  = $r0, 0x200 #__bss_start
        add  $r2  = $r0, 0x300 #__bss_stop
__clear_bss:
        swm  [$r1+0] = $r0
        swm  [$r1+1] = $r0
        swm  [$r1+2] = $r0
        swm  [$r1+3] = $r0
        add  $r1 = $r1, 4
        cmpult $p1 = $r1, $r2
  ($p1) br __clear_bss

        # 3. goto sta$rt_ke$rnel
l1:
        # 4. goto 3.
        br   l1
