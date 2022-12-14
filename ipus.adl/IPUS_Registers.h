enumerated = (
#ifndef MAKEDOC
#ifdef LOOPCNTB
              (loopcntb,r0),
#else
              r0,
#endif
              (loopcnt,r1),
              (xpos,r2),
              (ypos,r3),
              (confalu,r4),
              r5,r6,
              (confmxalu,r7),
              (confaddt,r8),
              (confthres,r9),
              (confsort,r10),
              (confbest,r11),
              (confhist,r12),
              (confstat,r13),
              r14,r15,
              (ina0 ,r16),
              (ina1 ,r17),
              (ina2 ,r18),
              (ina3 ,r19),
              (ina4 ,r20),
              (ina5 ,r21),
              (ina6 ,r22),
              (ina7 ,r23),
              (ina8 ,r24),
              r25,r26,r27,r28,r29,r30,r31,
              (inb0 ,r32),
              (inb1 ,r33),
              (inb2 ,r34),
              (inb3 ,r35),
              (inb4 ,r36),
              (inb5 ,r37),
              (inb6 ,r38),
              (inb7 ,r39),
              (inb8 ,r40),
              r41,r42,r43,r44,r45,r46,r47,
              (inalpha0 ,r48),
              (inalpha1 ,r49),
              (inalpha2 ,r50),
              (inalpha3 ,r51),
              (inalpha4 ,r52),
              (inalpha5 ,r53),
              (inalpha6 ,r54),
              (inalpha7 ,r55),
              (inalpha8 ,r56),
              r57,r58,r59,r60,r61,r62,r63,
              (w0 ,r64),
              (w1 ,r65),
              (w2 ,r66),
              (w3 ,r67),
              (w4 ,r68),
              (w5 ,r69),
              (w6 ,r70),
              (w7 ,r71),
              (w8 ,r72),
              r73,r74,r75,r76,r77,r78,r79,
              (ww0 ,r80),
              (ww1 ,r81),
              (ww2 ,r82),
              (ww3 ,r83),
              (ww4 ,r84),
              (ww5 ,r85),
              (ww6 ,r86),
              (ww7 ,r87),
              (ww8 ,r88),
              r89,r90,r91,r92,r93,r94,r95,
              (m0 ,r96),
              (m1 ,r97),
              (m2 ,r98),
              (m3 ,r99),
              (m4 ,r100),
              (m5 ,r101),
              (m6 ,r102),
              (m7 ,r103),
              (m8 ,r104),
              (maskv,r105),
              (nhood,r106),
              r107,
              (mflag_o,r108),
              (mflag_c,r109),
              (mflag_n,r110),
              (mflag_z,r111),
              (gpr0  ,r112),
              (gpr1  ,r113),
              (gpr2  ,r114),
              (gpr3  ,r115),
              (gpr4  ,r116),
              (gpr5  ,r117),
              (gpr6  ,r118),
              (gpr7  ,r119),
              (gpr8  ,r120),
              (gpr9  ,r121),
              (gpr10 ,r122),
              (gpr11 ,r123),
              (gpr12 ,r124),
              (gpr13 ,r125),
              (gpr14 ,r126),
              (gpr15 ,r127),
              (out0 ,r128),
              (out1 ,r129),
              (out2 ,r130),
              (out3 ,r131),
              r132,r133,r134,r135,
              r136,r137,r138,r139,r140,r141,r142,r143,
              (opixa0,r144),
              (opix0,r145),
              (opixa1,r146),
              (opix1,r147),
              r148,//(cmp0,r148),
              r149,//(cmp1,r149),
              r150,//(cmpl,r150),
              r151,//(cmpbe,r151),
              (acc0,r152),
              (acc1,r153),
              (acc2,r154),
              (acc3,r155),
              (sacc0,r156),
              (sacc1,r157),
              (sacc2,r158),
              (sacc3,r159),
              (sum,r160),
              (clipped,r161),
              (threshold,r162),
              (scaled,r163),
              (max,sortmax,r164),
              (min,sortmin,r165),
              (median,sortmedian,r166),
              (argmin,r167),
              (argmax,r168),
              r169,r170,r171,r172,r173,r174,r175,
              r176,r177,r178,r179,r180,r181,r182,r183,
              r184,r185,r186,r187,r188,r189,r190,r191,
              r192,r193,r194,r195,r196,r197,r198,r199,
              r200,r201,r202,r203,r204,r205,r206,r207,
              (luta,r208),
              (lut,r209),
              r210,r211,
              (hbina,r212),     // bin number to be added to
              (hbinadd,r213),   // value to add to HIST[hbina]
              (hbinincl,r214),  // bin to increment
              (hbininch,r215),  // bin to increment, value is processed according to config
              (sfl0,r216),      // statistics field 0, low word & and input
              (sfh0,r217),      // statistics field 0, high word (read onyl)
              (sfl1,r218),      // statistics field 1, low word & and input
              (sfh1,r219),      // statistics field 1, high word (read onyl)
              (sfl2,r220),      // statistics field 2, low word & and input
              (sfh2,r221),      // statistics field 2, high word (read onyl)
              (sfl3,r222),      // statistics field 3, low word & and input
              (sfh3,r223),      // statistics field 3, high word (read onyl)
              (srec,r224),      // statistics record number
              r225,r226,r227,r228,r229,r230,r231,
              r232,r233,r234,r235,r236,r237,r238,r239,
              (soin,r240),      // sort in new value
              (soclear,r241),   // clear sort list of best
              (so0,r242),       // best value
              (so1,r243),       // 2nd best value
              (so2,r244),       // 3rd best value
              (so3,r245),       // 4th best value
              (so4,r246),       // 5th best value
              (soa0,r247),      // argument of best value
              (soa1,r248),      // argument of 2nd best value
              (soa2,r249),      // argument of 3rd best value
              (soa3,r250),      // argument of 4th best value
              (soa4,r251),      // argument of 5th best value
              (lock,r252),
              (prng,r253),
              (one,r254),
              (zero,r255)
#else
#ifdef LOOPCNTB
              loopcntb,
#else
              reserved,
#endif
              loopcnt,
              xpos,
              ypos,
              confalu,
              reserved,reserved,
              confmxalu,
              confaddt,
              confthres,
              confsort,
              confbest,
              confhist,
              confstat,
              reserved,reserved,
              ina0,
              ina1,
              ina2,
              ina3,
              ina4,
              ina5,
              ina6,
              ina7,
              ina8,
              reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              inb0,
              inb1,
              inb2,
              inb3,
              inb4,
              inb5,
              inb6,
              inb7,
              inb8,
              reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              inalpha0,
              inalpha1,
              inalpha2,
              inalpha3,
              inalpha4,
              inalpha5,
              inalpha6,
              inalpha7,
              inalpha8,
              reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              w0,
              w1,
              w2,
              w3,
              w4,
              w5,
              w6,
              w7,
              w8,
              reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              ww0,
              ww1,
              ww2,
              ww3,
              ww4,
              ww5,
              ww6,
              ww7,
              ww8,
              reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              m0,
              m1,
              m2,
              m3,
              m4,
              m5,
              m6,
              m7,
              m8,
              maskv,
              nhood,
              reserved,
              mflag_o,
              mflag_c,
              mflag_n,
              mflag_z,
              gpr0,
              gpr1,
              gpr2,
              gpr3,
              gpr4,
              gpr5,
              gpr6,
              gpr7,
              gpr8,
              gpr9,
              gpr10,
              gpr11,
              gpr12,
              gpr13,
              gpr14,
              gpr15,
              out0,
              out1,
              out2,
              out3,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              opixa0,
              opix0,
              opixa1,
              opix1,
              reserved,//cmp0,
              reserved,//cmp1,
              reserved,//cmpl,
              reserved,//cmpbe,
              acc0,
              acc1,
              acc2,
              acc3,
              sacc0,
              sacc1,
              sacc2,
              sacc3,
              sum,
              clipped,
              threshold,
              scaled,
              (max,sortmax),
              (min,sortmin),
              (median,sortmedian),
              argmin,
              argmax,
              reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              luta,
              lut,
              reserved,reserved,
              hbina,     // bin number to be added to
              hbinadd,   // value to add to HIST[hbina]
              hbinincl,  // bin to increment
              hbininch,  // bin to increment, value is processed according to config
              sfl0,      // statistics field 0, low word & and input
              sfh0,      // statistics field 0, high word read onyl)
              sfl1,      // statistics field 1, low word & and input
              sfh1,      // statistics field 1, high word read onyl)
              sfl2,      // statistics field 2, low word & and input
              sfh2,      // statistics field 2, high word read onyl)
              sfl3,      // statistics field 3, low word & and input
              sfh3,      // statistics field 3, high word read onyl)
              srec,      // statistics record number
              reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              reserved,reserved,reserved,reserved,
              soin,      // sort in new value
              soclear,   // clear sort list of best
              so0,       // best value
              so1,       // 2nd best value
              so2,       // 3rd best value
              so3,       // 4th best value
              so4,       // 5th best value
              soa0,      // argument of best value
              soa1,      // argument of 2nd best value
              soa2,      // argument of 3rd best value
              soa3,      // argument of 4th best value
              soa4,      // argument of 5th best value
              lock,
              prng,
              one,
              zero
#endif
              );
