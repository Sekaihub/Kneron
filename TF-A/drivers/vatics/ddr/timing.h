#ifndef __TIMING_H__
#define __TIMING_H__

#define DFI_CLOCK       (DRAM_BUSCLK) // / 2)
#define max(ps, nCK)    (((ps * DFI_CLOCK / 1000000) >= nCK) ? (ps * DFI_CLOCK / 1000000) : nCK)
#define t2n(ps)         (ps * DFI_CLOCK / 1000000)

#define BL      (16)      // burst length

#define nWTR    max(10000, 8)      // WRITE-TO-READ
#define nRTP    max(7500, 8)     // internal READ to PRECHARGE command delay
#define nRCD    max(18000, 4)      // RAS-to-CAS delay
#define nRRD    max(10000, 4)      // Active bank A to active bank B
#define nXP     max(7500, 5)    // Exit power-down to next valid command

#define nFAW    (40000 * DFI_CLOCK / 1000000)   // Four-bank ACTIVATE window

#define tRFC    (280000)
#define nRFC    (tRFC * DFI_CLOCK / 1000000) // refresh cycle
#define nXS     max((tRFC + 7.5), 5)        // SELF REFRESH exit to next valid command
#define nXSR    max((tRFC + 7.5), 2)        // SELF REFRESH exit to next valid command. LPDDR4:

#define tREFI    (3900)
#define nREFI    ((tREFI * DFI_CLOCK / 1000) >> 1 >> 5)         // refresh interval

#define nRAS    max(42000, 3)      // row active
#define nRP     max(21000, 4)      // all bank
#define nRPpb   max(18000, 4)      // per bank
#define nRC     (nRAS + nRP)    // ACTIVATE to ACTIVATE

#if 0
#define nRL     ((DRAM_BUSCLK <= 800) ? 14 : \
                    (DRAM_BUSCLK <= 1066) ? 20 : \
                    (DRAM_BUSCLK <= 1333) ? 24 : \
                    (DRAM_BUSCLK <= 1600) ? 28 : \
                    (DRAM_BUSCLK <= 1866) ? 32 : 36 )
#else
#define nRL     (((((DRAM_BUSCLK + 265) / 266) + 1) * 4))
#endif
#define nWL     (nRL / 2)   //
#define nWR     max(18000, 6)  // WRITE recovery time

#define nSR     max(15000, 3)  // Minimum Self-Refresh Time
#define nCCD    (8)         // CAS-to-CAS delay
#define nPPD    (4)         // Precharge to Precharge

#define nMRD    max(14000, 10)     //
#define nMRW    max(10000, 10)     //

#endif
