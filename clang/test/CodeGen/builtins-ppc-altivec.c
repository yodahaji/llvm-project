// RUN: %clang_cc1 -faltivec -triple powerpc-unknown-unknown -emit-llvm %s -o - | FileCheck %s

int main ()
{
  // TODO: uncomment
/*  vector bool char vbc = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }; */
  vector signed char vsc = { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16 };
  vector unsigned char vuc = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
  // TODO: uncomment
/*  vector bool short vbs = { 1, 0, 1, 0, 1, 0, 1, 0 }; */
  vector short vs = { -1, 2, -3, 4, -5, 6, -7, 8 };
  vector unsigned short vus = { 1, 2, 3, 4, 5, 6, 7, 8 };
  // TODO: uncomment
/*  vector bool int vbi = { 1, 0, 1, 0 }; */
  vector int vi = { -1, 2, -3, 4 };
  vector unsigned int vui = { 1, 2, 3, 4 };
  vector float vf = { -1.5, 2.5, -3.5, 4.5 };

  // TODO: uncomment
/*  vector bool char res_vbc; */
  vector signed char res_vsc;
  vector unsigned char res_vuc;
  // TODO: uncomment
/*  vector bool short res_vbs; */
  vector short res_vs;
  vector unsigned short res_vus;
  // TODO: uncomment
  vector pixel res_vp;
  // TODO: uncomment
/*  vector bool int res_vbi; */
  vector int res_vi;
  vector unsigned int res_vui;
  vector float res_vf;

  signed char param_sc;
  unsigned char param_uc;
  short param_s;
  unsigned short param_us;
  int param_i;
  unsigned int param_ui;
  float param_f;

  int res_i;

  /* vec_abs */
  vsc = vec_abs(vsc);                           // CHECK: sub nsw <16 x i8> zeroinitializer
                                                // CHECK: @llvm.ppc.altivec.vmaxsb

  vs = vec_abs(vs);                             // CHECK: sub nsw <8 x i16> zeroinitializer
                                                // CHECK: @llvm.ppc.altivec.vmaxsh

  vi = vec_abs(vi);                             // CHECK: sub nsw <4 x i32> zeroinitializer
                                                // CHECK: @llvm.ppc.altivec.vmaxsw

  vf = vec_abs(vf);                             // CHECK: and <4 x i32>

  /* vec_abs */
  vsc = vec_abss(vsc);                          // CHECK: @llvm.ppc.altivec.vsubsbs
                                                // CHECK: @llvm.ppc.altivec.vmaxsb

  vs = vec_abss(vs);                            // CHECK: @llvm.ppc.altivec.vsubshs
                                                // CHECK: @llvm.ppc.altivec.vmaxsh

  vi = vec_abss(vi);                            // CHECK: @llvm.ppc.altivec.vsubsws
                                                // CHECK: @llvm.ppc.altivec.vmaxsw

  /*  vec_add */
  res_vsc = vec_add(vsc, vsc);                  // CHECK: add nsw <16 x i8>
  res_vuc = vec_add(vuc, vuc);                  // CHECK: add <16 x i8>
  res_vs  = vec_add(vs, vs);                    // CHECK: add nsw <8 x i16>
  res_vus = vec_add(vus, vus);                  // CHECK: add <8 x i16>
  res_vi  = vec_add(vi, vi);                    // CHECK: add nsw <4 x i32>
  res_vui = vec_add(vui, vui);                  // CHECK: add <4 x i32>
  res_vf  = vec_add(vf, vf);                    // CHECK: fadd <4 x float>
  res_vsc = vec_vaddubm(vsc, vsc);              // CHECK: add nsw <16 x i8>
  res_vuc = vec_vaddubm(vuc, vuc);              // CHECK: add <16 x i8>
  res_vs  = vec_vadduhm(vs, vs);                // CHECK: add nsw <8 x i16>
  res_vus = vec_vadduhm(vus, vus);              // CHECK: add <8 x i16>
  res_vi  = vec_vadduwm(vi, vi);                // CHECK: add nsw <4 x i32>
  res_vui = vec_vadduwm(vui, vui);              // CHECK: add <4 x i32>
  res_vf  = vec_vaddfp(vf, vf);                 // CHECK: fadd <4 x float>

  /* vec_addc */
  res_vui = vec_addc(vui, vui);                 // HECK: @llvm.ppc.altivec.vaddcuw
  res_vui = vec_vaddcuw(vui, vui);              // HECK: @llvm.ppc.altivec.vaddcuw

  /* vec_adds */
  res_vsc = vec_adds(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vaddsbs
  res_vuc = vec_adds(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vaddubs
  res_vs  = vec_adds(vs, vs);                   // CHECK: @llvm.ppc.altivec.vaddshs
  res_vus = vec_adds(vus, vus);                 // CHECK: @llvm.ppc.altivec.vadduhs
  res_vi  = vec_adds(vi, vi);                   // CHECK: @llvm.ppc.altivec.vaddsws
  res_vui = vec_adds(vui, vui);                 // CHECK: @llvm.ppc.altivec.vadduws
  res_vsc = vec_vaddsbs(vsc, vsc);              // CHECK: @llvm.ppc.altivec.vaddsbs
  res_vuc = vec_vaddubs(vuc, vuc);              // CHECK: @llvm.ppc.altivec.vaddubs
  res_vs  = vec_vaddshs(vs, vs);                // CHECK: @llvm.ppc.altivec.vaddshs
  res_vus = vec_vadduhs(vus, vus);              // CHECK: @llvm.ppc.altivec.vadduhs
  res_vi  = vec_vaddsws(vi, vi);                // CHECK: @llvm.ppc.altivec.vaddsws
  res_vui = vec_vadduws(vui, vui);              // CHECK: @llvm.ppc.altivec.vadduws

  /* vec_and */
  res_vsc = vec_and(vsc, vsc);                  // CHECK: and <16 x i8>
  res_vuc = vec_and(vuc, vuc);                  // CHECK: and <16 x i8>
  res_vs  = vec_and(vs, vs);                    // CHECK: and <8 x i16>
  res_vus = vec_and(vus, vus);                  // CHECK: and <8 x i16>
  res_vi  = vec_and(vi, vi);                    // CHECK: and <4 x i32>
  res_vui = vec_and(vui, vui);                  // CHECK: and <4 x i32>
  res_vsc = vec_vand(vsc, vsc);                 // CHECK: and <16 x i8>
  res_vuc = vec_vand(vuc, vuc);                 // CHECK: and <16 x i8>
  res_vs  = vec_vand(vs, vs);                   // CHECK: and <8 x i16>
  res_vus = vec_vand(vus, vus);                 // CHECK: and <8 x i16>
  res_vi  = vec_vand(vi, vi);                   // CHECK: and <4 x i32>
  res_vui = vec_vand(vui, vui);                 // CHECK: and <4 x i32>

  /* vec_andc */
  res_vsc = vec_andc(vsc, vsc);                 // CHECK: xor <16 x i8>
                                                // CHECK: and <16 x i8>

  res_vuc = vec_andc(vuc, vuc);                 // CHECK: xor <16 x i8>
                                                // CHECK: and <16 x i8>

  res_vs  = vec_andc(vs, vs);                   // CHECK: xor <8 x i16>
                                                // CHECK: and <8 x i16>

  res_vus = vec_andc(vus, vus);                 // CHECK: xor <8 x i16>
                                                // CHECK: and <8 x i16>

  res_vi  = vec_andc(vi, vi);                   // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>

  res_vui = vec_andc(vui, vui);                 // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>

  res_vf = vec_andc(vf, vf);                    // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>

  res_vsc = vec_vandc(vsc, vsc);                // CHECK: xor <16 x i8>
                                                // CHECK: and <16 x i8>

  res_vuc = vec_vandc(vuc, vuc);                // CHECK: xor <16 x i8>
                                                // CHECK: and <16 x i8>

  res_vs  = vec_vandc(vs, vs);                  // CHECK: xor <8 x i16>
                                                // CHECK: and <8 x i16>

  res_vus = vec_vandc(vus, vus);                // CHECK: xor <8 x i16>
                                                // CHECK: and <8 x i16>

  res_vi  = vec_vandc(vi, vi);                  // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>

  res_vui = vec_vandc(vui, vui);                // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>

  res_vf = vec_vandc(vf, vf);                   // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>

  /* vec_avg */
  res_vsc = vec_avg(vsc, vsc);                  // CHECK: @llvm.ppc.altivec.vavgsb
  res_vuc = vec_avg(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vavgub
  res_vs  = vec_avg(vs, vs);                    // CHECK: @llvm.ppc.altivec.vavgsh
  res_vus = vec_avg(vus, vus);                  // CHECK: @llvm.ppc.altivec.vavguh
  res_vi  = vec_avg(vi, vi);                    // CHECK: @llvm.ppc.altivec.vavgsw
  res_vui = vec_avg(vui, vui);                  // CHECK: @llvm.ppc.altivec.vavguw
  res_vsc = vec_vavgsb(vsc, vsc);               // CHECK: @llvm.ppc.altivec.vavgsb
  res_vuc = vec_vavgub(vuc, vuc);               // CHECK: @llvm.ppc.altivec.vavgub
  res_vs  = vec_vavgsh(vs, vs);                 // CHECK: @llvm.ppc.altivec.vavgsh
  res_vus = vec_vavguh(vus, vus);               // CHECK: @llvm.ppc.altivec.vavguh
  res_vi  = vec_vavgsw(vi, vi);                 // CHECK: @llvm.ppc.altivec.vavgsw
  res_vui = vec_vavguw(vui, vui);               // CHECK: @llvm.ppc.altivec.vavguw

  /* vec_ceil */
  res_vf = vec_ceil(vf);                        // CHECK: @llvm.ppc.altivec.vrfip
  res_vf = vec_vrfip(vf);                       // CHECK: @llvm.ppc.altivec.vrfip

  /* vec_cmpb */
  res_vi = vec_cmpb(vf, vf);                    // CHECK: @llvm.ppc.altivec.vcmpbfp
  res_vi = vec_vcmpbfp(vf, vf);                 // CHECK: @llvm.ppc.altivec.vcmpbfp

  /* vec_cmpeq */
  // TODO: uncomment
  /*res_vbc = */vec_cmpeq(vsc, vsc);            // CHECK: @llvm.ppc.altivec.vcmpequb
  /*res_vbc = */vec_cmpeq(vuc, vuc);            // CHECK: @llvm.ppc.altivec.vcmpequb
  /*res_vbs = */vec_cmpeq(vs, vs);              // CHECK: @llvm.ppc.altivec.vcmpequh
  /*res_vbs = */vec_cmpeq(vus, vus);            // CHECK: @llvm.ppc.altivec.vcmpequh
  /*res_vbi = */vec_cmpeq(vi, vi);              // CHECK: @llvm.ppc.altivec.vcmpequw
  /*res_vbi = */vec_cmpeq(vui, vui);            // CHECK: @llvm.ppc.altivec.vcmpequw
  /*res_vbi = */vec_cmpeq(vf, vf);              // CHECK: @llvm.ppc.altivec.vcmpeqfp

  /* vec_cmpge */
  // TODO: uncomment
  /*res_vbi = */vec_cmpge(vf, vf);              // CHECK: @llvm.ppc.altivec.vcmpgefp
  /*res_vbi = */vec_vcmpgefp(vf, vf);           // CHECK: @llvm.ppc.altivec.vcmpgefp

  /* vec_cmpgt */
  // TODO: uncomment
  /*res_vbc = */vec_cmpgt(vsc, vsc);            // CHECK: @llvm.ppc.altivec.vcmpgtsb
  /*res_vbc = */vec_cmpgt(vuc, vuc);            // CHECK: @llvm.ppc.altivec.vcmpgtub
  /*res_vbs = */vec_cmpgt(vs, vs);              // CHECK: @llvm.ppc.altivec.vcmpgtsh
  /*res_vbs = */vec_cmpgt(vus, vus);            // CHECK: @llvm.ppc.altivec.vcmpgtuh
  /*res_vbi = */vec_cmpgt(vi, vi);              // CHECK: @llvm.ppc.altivec.vcmpgtsw
  /*res_vbi = */vec_cmpgt(vui, vui);            // CHECK: @llvm.ppc.altivec.vcmpgtuw
  /*res_vbi = */vec_cmpgt(vf, vf);              // CHECK: @llvm.ppc.altivec.vcmpgtfp
  /*res_vbc = */vec_vcmpgtsb(vsc, vsc);         // CHECK: @llvm.ppc.altivec.vcmpgtsb
  /*res_vbc = */vec_vcmpgtub(vuc, vuc);         // CHECK: @llvm.ppc.altivec.vcmpgtub
  /*res_vbs = */vec_vcmpgtsh(vs, vs);           // CHECK: @llvm.ppc.altivec.vcmpgtsh
  /*res_vbs = */vec_vcmpgtuh(vus, vus);         // CHECK: @llvm.ppc.altivec.vcmpgtuh
  /*res_vbi = */vec_vcmpgtsw(vi, vi);           // CHECK: @llvm.ppc.altivec.vcmpgtsw
  /*res_vbi = */vec_vcmpgtuw(vui, vui);         // CHECK: @llvm.ppc.altivec.vcmpgtuw
  /*res_vbi = */vec_vcmpgtfp(vf, vf);           // CHECK: @llvm.ppc.altivec.vcmpgtfp

  /* vec_cmple */
  // TODO: uncomment
  /*res_vbi = */vec_cmple(vf, vf);              // CHECK: @llvm.ppc.altivec.vcmpgefp

  /* vec_cmplt */
  // TODO: uncomment
  /*res_vbc = */vec_cmplt(vsc, vsc);            // CHECK: @llvm.ppc.altivec.vcmpgtsb
  /*res_vbc = */vec_cmplt(vuc, vuc);            // CHECK: @llvm.ppc.altivec.vcmpgtub
  /*res_vbs = */vec_cmplt(vs, vs);              // CHECK: @llvm.ppc.altivec.vcmpgtsh
  /*res_vbs = */vec_cmplt(vus, vus);            // CHECK: @llvm.ppc.altivec.vcmpgtuh
  /*res_vbi = */vec_cmplt(vi, vi);              // CHECK: @llvm.ppc.altivec.vcmpgtsw
  /*res_vbi = */vec_cmplt(vui, vui);            // CHECK: @llvm.ppc.altivec.vcmpgtuw
  /*res_vbi = */vec_cmplt(vf, vf);              // CHECK: @llvm.ppc.altivec.vcmpgtfp

  /* vec_ctf */
  res_vf  = vec_ctf(vi, param_i);               // CHECK: @llvm.ppc.altivec.vcfsx
  res_vf  = vec_ctf(vui, 0);                    // CHECK: @llvm.ppc.altivec.vcfux
  res_vf  = vec_vcfsx(vi, 0);                   // CHECK: @llvm.ppc.altivec.vcfsx
  res_vf  = vec_vcfux(vui, 0);                  // CHECK: @llvm.ppc.altivec.vcfux

  /* vec_cts */
  res_vi = vec_cts(vf, 0);                      // CHECK: @llvm.ppc.altivec.vctsxs
  res_vi = vec_vctsxs(vf, 0);                   // CHECK: @llvm.ppc.altivec.vctsxs

  /* vec_ctu */
  res_vui = vec_ctu(vf, 0);                     // CHECK: @llvm.ppc.altivec.vctuxs
  res_vui = vec_vctuxs(vf, 0);                  // CHECK: @llvm.ppc.altivec.vctuxs

  /* vec_dss */
  vec_dss(param_i);                             // CHECK: @llvm.ppc.altivec.dss

  /* vec_dssall */
  vec_dssall();                                 // CHECK: @llvm.ppc.altivec.dssall

  /* vec_dst */
  vec_dst(&vsc, 0, 0);                          // CHECK: @llvm.ppc.altivec.dst

  /* vec_dstst */
  vec_dstst(&vs, 0, 0);                         // CHECK: @llvm.ppc.altivec.dstst

  /* vec_dststt */
  vec_dststt(&param_i, 0, 0);                   // CHECK: @llvm.ppc.altivec.dststt

  /* vec_dstt */
  vec_dstt(&vf, 0, 0);                          // CHECK: @llvm.ppc.altivec.dstt

  /* vec_expte */
  res_vf = vec_expte(vf);                       // CHECK: @llvm.ppc.altivec.vexptefp
  res_vf = vec_vexptefp(vf);                    // CHECK: @llvm.ppc.altivec.vexptefp

  /* vec_floor */
  res_vf = vec_floor(vf);                       // CHECK: @llvm.ppc.altivec.vrfim
  res_vf = vec_vrfim(vf);                       // CHECK: @llvm.ppc.altivec.vrfim

  /* vec_ld */
  res_vsc = vec_ld(0, &vsc);                    // CHECK: @llvm.ppc.altivec.lvx
  res_vsc = vec_ld(0, &param_sc);               // CHECK: @llvm.ppc.altivec.lvx
  res_vuc = vec_ld(0, &vuc);                    // CHECK: @llvm.ppc.altivec.lvx
  res_vuc = vec_ld(0, &param_uc);               // CHECK: @llvm.ppc.altivec.lvx
  res_vs  = vec_ld(0, &vs);                     // CHECK: @llvm.ppc.altivec.lvx
  res_vs  = vec_ld(0, &param_s);                // CHECK: @llvm.ppc.altivec.lvx
  res_vus = vec_ld(0, &vus);                    // CHECK: @llvm.ppc.altivec.lvx
  res_vus = vec_ld(0, &param_us);               // CHECK: @llvm.ppc.altivec.lvx
  res_vi  = vec_ld(0, &vi);                     // CHECK: @llvm.ppc.altivec.lvx
  res_vi  = vec_ld(0, &param_i);                // CHECK: @llvm.ppc.altivec.lvx
  res_vui = vec_ld(0, &vui);                    // CHECK: @llvm.ppc.altivec.lvx
  res_vui = vec_ld(0, &param_ui);               // CHECK: @llvm.ppc.altivec.lvx
  res_vf  = vec_ld(0, &vf);                     // CHECK: @llvm.ppc.altivec.lvx
  res_vf  = vec_ld(0, &param_f);                // CHECK: @llvm.ppc.altivec.lvx
  res_vsc = vec_lvx(0, &vsc);                   // CHECK: @llvm.ppc.altivec.lvx
  res_vsc = vec_lvx(0, &param_sc);              // CHECK: @llvm.ppc.altivec.lvx
  res_vuc = vec_lvx(0, &vuc);                   // CHECK: @llvm.ppc.altivec.lvx
  res_vuc = vec_lvx(0, &param_uc);              // CHECK: @llvm.ppc.altivec.lvx
  res_vs  = vec_lvx(0, &vs);                    // CHECK: @llvm.ppc.altivec.lvx
  res_vs  = vec_lvx(0, &param_s);               // CHECK: @llvm.ppc.altivec.lvx
  res_vus = vec_lvx(0, &vus);                   // CHECK: @llvm.ppc.altivec.lvx
  res_vus = vec_lvx(0, &param_us);              // CHECK: @llvm.ppc.altivec.lvx
  res_vi  = vec_lvx(0, &vi);                    // CHECK: @llvm.ppc.altivec.lvx
  res_vi  = vec_lvx(0, &param_i);               // CHECK: @llvm.ppc.altivec.lvx
  res_vui = vec_lvx(0, &vui);                   // CHECK: @llvm.ppc.altivec.lvx
  res_vui = vec_lvx(0, &param_ui);              // CHECK: @llvm.ppc.altivec.lvx
  res_vf  = vec_lvx(0, &vf);                    // CHECK: @llvm.ppc.altivec.lvx
  res_vf  = vec_lvx(0, &param_f);               // CHECK: @llvm.ppc.altivec.lvx

  /* vec_lde */
  res_vsc = vec_lde(0, &vsc);                   // CHECK: @llvm.ppc.altivec.lvebx
  res_vuc = vec_lde(0, &vuc);                   // CHECK: @llvm.ppc.altivec.lvebx
  res_vs  = vec_lde(0, &vs);                    // CHECK: @llvm.ppc.altivec.lvehx
  res_vus = vec_lde(0, &vus);                   // CHECK: @llvm.ppc.altivec.lvehx
  res_vi  = vec_lde(0, &vi);                    // CHECK: @llvm.ppc.altivec.lvewx
  res_vui = vec_lde(0, &vui);                   // CHECK: @llvm.ppc.altivec.lvewx
  res_vf  = vec_lde(0, &vf);                    // CHECK: @llvm.ppc.altivec.lvewx
  res_vsc = vec_lvebx(0, &vsc);                 // CHECK: @llvm.ppc.altivec.lvebx
  res_vuc = vec_lvebx(0, &vuc);                 // CHECK: @llvm.ppc.altivec.lvebx
  res_vs  = vec_lvehx(0, &vs);                  // CHECK: @llvm.ppc.altivec.lvehx
  res_vus = vec_lvehx(0, &vus);                 // CHECK: @llvm.ppc.altivec.lvehx
  res_vi  = vec_lvewx(0, &vi);                  // CHECK: @llvm.ppc.altivec.lvewx
  res_vui = vec_lvewx(0, &vui);                 // CHECK: @llvm.ppc.altivec.lvewx
  res_vf  = vec_lvewx(0, &vf);                  // CHECK: @llvm.ppc.altivec.lvewx

  /* vec_ldl */
  res_vsc = vec_ldl(0, &vsc);                   // CHECK: @llvm.ppc.altivec.lvxl
  res_vsc = vec_ldl(0, &param_sc);              // CHECK: @llvm.ppc.altivec.lvxl
  res_vuc = vec_ldl(0, &vuc);                   // CHECK: @llvm.ppc.altivec.lvxl
  res_vuc = vec_ldl(0, &param_uc);              // CHECK: @llvm.ppc.altivec.lvxl
  res_vs  = vec_ldl(0, &vs);                    // CHECK: @llvm.ppc.altivec.lvxl
  res_vs  = vec_ldl(0, &param_s);               // CHECK: @llvm.ppc.altivec.lvxl
  res_vus = vec_ldl(0, &vus);                   // CHECK: @llvm.ppc.altivec.lvxl
  res_vus = vec_ldl(0, &param_us);              // CHECK: @llvm.ppc.altivec.lvxl
  res_vi  = vec_ldl(0, &vi);                    // CHECK: @llvm.ppc.altivec.lvxl
  res_vi  = vec_ldl(0, &param_i);               // CHECK: @llvm.ppc.altivec.lvxl
  res_vui = vec_ldl(0, &vui);                   // CHECK: @llvm.ppc.altivec.lvxl
  res_vui = vec_ldl(0, &param_ui);              // CHECK: @llvm.ppc.altivec.lvxl
  res_vf  = vec_ldl(0, &vf);                    // CHECK: @llvm.ppc.altivec.lvxl
  res_vf  = vec_ldl(0, &param_f);               // CHECK: @llvm.ppc.altivec.lvxl
  res_vsc = vec_lvxl(0, &vsc);                  // CHECK: @llvm.ppc.altivec.lvxl
  res_vsc = vec_lvxl(0, &param_sc);             // CHECK: @llvm.ppc.altivec.lvxl
  res_vuc = vec_lvxl(0, &vuc);                  // CHECK: @llvm.ppc.altivec.lvxl
  res_vuc = vec_lvxl(0, &param_uc);             // CHECK: @llvm.ppc.altivec.lvxl
  res_vs  = vec_lvxl(0, &vs);                   // CHECK: @llvm.ppc.altivec.lvxl
  res_vs  = vec_lvxl(0, &param_s);              // CHECK: @llvm.ppc.altivec.lvxl
  res_vus = vec_lvxl(0, &vus);                  // CHECK: @llvm.ppc.altivec.lvxl
  res_vus = vec_lvxl(0, &param_us);             // CHECK: @llvm.ppc.altivec.lvxl
  res_vi  = vec_lvxl(0, &vi);                   // CHECK: @llvm.ppc.altivec.lvxl
  res_vi  = vec_lvxl(0, &param_i);              // CHECK: @llvm.ppc.altivec.lvxl
  res_vui = vec_lvxl(0, &vui);                  // CHECK: @llvm.ppc.altivec.lvxl
  res_vui = vec_lvxl(0, &param_ui);             // CHECK: @llvm.ppc.altivec.lvxl
  res_vf  = vec_lvxl(0, &vf);                   // CHECK: @llvm.ppc.altivec.lvxl
  res_vf  = vec_lvxl(0, &param_f);              // CHECK: @llvm.ppc.altivec.lvxl

  /* vec_loge */
  res_vf = vec_loge(vf);                        // CHECK: @llvm.ppc.altivec.vlogefp
  res_vf = vec_vlogefp(vf);                     // CHECK: @llvm.ppc.altivec.vlogefp

  /* vec_lvsl */
  res_vuc = vec_lvsl(0, &param_i);              // CHECK: @llvm.ppc.altivec.lvsl

  /* vec_lvsr */
  res_vuc = vec_lvsr(0, &param_i);              // CHECK: @llvm.ppc.altivec.lvsr

  /* vec_madd */
  res_vf =vec_madd(vf, vf, vf);                 // CHECK: @llvm.ppc.altivec.vmaddfp
  res_vf = vec_vmaddfp(vf, vf, vf);             // CHECK: @llvm.ppc.altivec.vmaddfp

  /* vec_madds */
  res_vs = vec_madds(vs, vs, vs);               // CHECK: @llvm.ppc.altivec.vmhaddshs
  res_vs = vec_vmhaddshs(vs, vs, vs);           // CHECK: @llvm.ppc.altivec.vmhaddshs

  /* vec_max */
  res_vsc = vec_max(vsc, vsc);                  // CHECK: @llvm.ppc.altivec.vmaxsb
  res_vuc = vec_max(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vmaxub
  res_vs  = vec_max(vs, vs);                    // CHECK: @llvm.ppc.altivec.vmaxsh
  res_vus = vec_max(vus, vus);                  // CHECK: @llvm.ppc.altivec.vmaxuh
  res_vi  = vec_max(vi, vi);                    // CHECK: @llvm.ppc.altivec.vmaxsw
  res_vui = vec_max(vui, vui);                  // CHECK: @llvm.ppc.altivec.vmaxuw
  res_vf  = vec_max(vf, vf);                    // CHECK: @llvm.ppc.altivec.vmaxfp
  res_vsc = vec_vmaxsb(vsc, vsc);               // CHECK: @llvm.ppc.altivec.vmaxsb
  res_vuc = vec_vmaxub(vuc, vuc);               // CHECK: @llvm.ppc.altivec.vmaxub
  res_vs  = vec_vmaxsh(vs, vs);                 // CHECK: @llvm.ppc.altivec.vmaxsh
  res_vus = vec_vmaxuh(vus, vus);               // CHECK: @llvm.ppc.altivec.vmaxuh
  res_vi  = vec_vmaxsw(vi, vi);                 // CHECK: @llvm.ppc.altivec.vmaxsw
  res_vui = vec_vmaxuw(vui, vui);               // CHECK: @llvm.ppc.altivec.vmaxuw
  res_vf  = vec_vmaxfp(vf, vf);                 // CHECK: @llvm.ppc.altivec.vmaxfp

  /* vec_mergeh */
  res_vsc = vec_mergeh(vsc, vsc);               // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_mergeh(vuc, vuc);               // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_mergeh(vs, vs);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_mergeh(vus, vus);               // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_mergeh(vi, vi);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_mergeh(vui, vui);               // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_mergeh(vf, vf);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vsc = vec_vmrghb(vsc, vsc);               // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_vmrghb(vuc, vuc);               // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_vmrghh(vs, vs);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_vmrghh(vus, vus);               // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_vmrghw(vi, vi);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_vmrghw(vui, vui);               // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_vmrghw(vf, vf);                 // CHECK: @llvm.ppc.altivec.vperm

  /* vec_mergel */
  res_vsc = vec_mergel(vsc, vsc);               // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_mergel(vuc, vuc);               // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_mergel(vs, vs);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_mergel(vus, vus);               // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_mergel(vi, vi);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_mergel(vui, vui);               // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_mergel(vf, vf);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vsc = vec_vmrglb(vsc, vsc);               // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_vmrglb(vuc, vuc);               // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_vmrglh(vs, vs);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_vmrglh(vus, vus);               // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_vmrglw(vi, vi);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_vmrglw(vui, vui);               // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_vmrglw(vf, vf);                 // CHECK: @llvm.ppc.altivec.vperm

  /* vec_mfvscr */
  vus = vec_mfvscr();                           // CHECK: @llvm.ppc.altivec.mfvscr

  /* vec_min */
  res_vsc = vec_min(vsc, vsc);                  // CHECK: @llvm.ppc.altivec.vminsb
  res_vuc = vec_min(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vminub
  res_vs  = vec_min(vs, vs);                    // CHECK: @llvm.ppc.altivec.vminsh
  res_vus = vec_min(vus, vus);                  // CHECK: @llvm.ppc.altivec.vminuh
  res_vi  = vec_min(vi, vi);                    // CHECK: @llvm.ppc.altivec.vminsw
  res_vui = vec_min(vui, vui);                  // CHECK: @llvm.ppc.altivec.vminuw
  res_vf  = vec_min(vf, vf);                    // CHECK: @llvm.ppc.altivec.vminfp
  res_vsc = vec_vminsb(vsc, vsc);               // CHECK: @llvm.ppc.altivec.vminsb
  res_vuc = vec_vminub(vuc, vuc);               // CHECK: @llvm.ppc.altivec.vminub
  res_vs  = vec_vminsh(vs, vs);                 // CHECK: @llvm.ppc.altivec.vminsh
  res_vus = vec_vminuh(vus, vus);               // CHECK: @llvm.ppc.altivec.vminuh
  res_vi  = vec_vminsw(vi, vi);                 // CHECK: @llvm.ppc.altivec.vminsw
  res_vui = vec_vminuw(vui, vui);               // CHECK: @llvm.ppc.altivec.vminuw
  res_vf  = vec_vminfp(vf, vf);                 // CHECK: @llvm.ppc.altivec.vminfp

  /* vec_mladd */
  res_vus = vec_mladd(vus, vus, vus);           // CHECK: mul <8 x i16>
                                                // CHECK: add <8 x i16>

  res_vs = vec_mladd(vus, vs, vs);              // CHECK: mul nsw <8 x i16>
                                                // CHECK: add nsw <8 x i16>

  res_vs = vec_mladd(vs, vus, vus);             // CHECK: mul nsw <8 x i16>
                                                // CHECK: add nsw <8 x i16>

  res_vs = vec_mladd(vs, vs, vs);               // CHECK: mul nsw <8 x i16>
                                                // CHECK: add nsw <8 x i16>

  /* vec_mradds */
  res_vs = vec_mradds(vs, vs, vs);              // CHECK: @llvm.ppc.altivec.vmhraddshs
  res_vs = vec_vmhraddshs(vs, vs, vs);          // CHECK: @llvm.ppc.altivec.vmhraddshs
 
  /* vec_msum */
  res_vi  = vec_msum(vsc, vuc, vi);             // CHECK: @llvm.ppc.altivec.vmsummbm
  res_vui = vec_msum(vuc, vuc, vui);            // CHECK: @llvm.ppc.altivec.vmsumubm
  res_vi  = vec_msum(vs, vs, vi);               // CHECK: @llvm.ppc.altivec.vmsumshm
  res_vui = vec_msum(vus, vus, vui);            // CHECK: @llvm.ppc.altivec.vmsumuhm
  res_vi  = vec_vmsummbm(vsc, vuc, vi);         // CHECK: @llvm.ppc.altivec.vmsummbm
  res_vui = vec_vmsumubm(vuc, vuc, vui);        // CHECK: @llvm.ppc.altivec.vmsumubm
  res_vi  = vec_vmsumshm(vs, vs, vi);           // CHECK: @llvm.ppc.altivec.vmsumshm
  res_vui = vec_vmsumuhm(vus, vus, vui);        // CHECK: @llvm.ppc.altivec.vmsumuhm

  /* vec_msums */
  res_vi  = vec_msums(vs, vs, vi);              // CHECK: @llvm.ppc.altivec.vmsumshs
  res_vui = vec_msums(vus, vus, vui);           // CHECK: @llvm.ppc.altivec.vmsumuhs
  res_vi  = vec_vmsumshs(vs, vs, vi);           // CHECK: @llvm.ppc.altivec.vmsumshs
  res_vui = vec_vmsumuhs(vus, vus, vui);        // CHECK: @llvm.ppc.altivec.vmsumuhs

  /* vec_mtvscr */
  vec_mtvscr(vsc);                              // CHECK: @llvm.ppc.altivec.mtvscr

  /* vec_mule */
  res_vs  = vec_mule(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vmulesb
  res_vus = vec_mule(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vmuleub
  res_vi  = vec_mule(vs, vs);                   // CHECK: @llvm.ppc.altivec.vmulesh
  res_vui = vec_mule(vus, vus);                 // CHECK: @llvm.ppc.altivec.vmuleuh
  res_vs  = vec_vmulesb(vsc, vsc);              // CHECK: @llvm.ppc.altivec.vmulesb
  res_vus = vec_vmuleub(vuc, vuc);              // CHECK: @llvm.ppc.altivec.vmuleub
  res_vi  = vec_vmulesh(vs, vs);                // CHECK: @llvm.ppc.altivec.vmulesh
  res_vui = vec_vmuleuh(vus, vus);              // CHECK: @llvm.ppc.altivec.vmuleuh

  /* vec_mulo */
  res_vs  = vec_mulo(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vmulosb
  res_vus = vec_mulo(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vmuloub
  res_vi  = vec_mulo(vs, vs);                   // CHECK: @llvm.ppc.altivec.vmulosh
  res_vui = vec_mulo(vus, vus);                 // CHECK: @llvm.ppc.altivec.vmulouh
  res_vs  = vec_vmulosb(vsc, vsc);              // CHECK: @llvm.ppc.altivec.vmulosb
  res_vus = vec_vmuloub(vuc, vuc);              // CHECK: @llvm.ppc.altivec.vmuloub
  res_vi  = vec_vmulosh(vs, vs);                // CHECK: @llvm.ppc.altivec.vmulosh
  res_vui = vec_vmulouh(vus, vus);              // CHECK: @llvm.ppc.altivec.vmulouh

  /* vec_nmsub */
  res_vf = vec_nmsub(vf, vf, vf);               // CHECK: @llvm.ppc.altivec.vnmsubfp
  res_vf = vec_vnmsubfp(vf, vf, vf);            // CHECK: @llvm.ppc.altivec.vnmsubfp

  /* vec_nor */
  res_vsc = vec_nor(vsc, vsc);                  // CHECK: or <16 x i8>
                                                // CHECK: xor <16 x i8>

  res_vuc = vec_nor(vuc, vuc);                  // CHECK: or <16 x i8>
                                                // CHECK: xor <16 x i8>

  res_vs  = vec_nor(vs, vs);                    // CHECK: or <8 x i16>
                                                // CHECK: xor <8 x i16>

  res_vus = vec_nor(vus, vus);                  // CHECK: or <8 x i16>
                                                // CHECK: xor <8 x i16>

  res_vi  = vec_nor(vi, vi);                    // CHECK: or <4 x i32>
                                                // CHECK: xor <4 x i32>

  res_vui = vec_nor(vui, vui);                  // CHECK: or <4 x i32>
                                                // CHECK: xor <4 x i32>

  res_vf  = vec_nor(vf, vf);                    // CHECK: or <4 x i32>
                                                // CHECK: xor <4 x i32>

  res_vsc = vec_vnor(vsc, vsc);                 // CHECK: or <16 x i8>
                                                // CHECK: xor <16 x i8>

  res_vuc = vec_vnor(vuc, vuc);                 // CHECK: or <16 x i8>
                                                // CHECK: xor <16 x i8>

  res_vs  = vec_vnor(vs, vs);                   // CHECK: or <8 x i16>
                                                // CHECK: xor <8 x i16>

  res_vus = vec_vnor(vus, vus);                 // CHECK: or <8 x i16>
                                                // CHECK: xor <8 x i16>

  res_vi  = vec_vnor(vi, vi);                   // CHECK: or <4 x i32>
                                                // CHECK: xor <4 x i32>

  res_vui = vec_vnor(vui, vui);                 // CHECK: or <4 x i32>
                                                // CHECK: xor <4 x i32>

  res_vf  = vec_vnor(vf, vf);                   // CHECK: or <4 x i32>
                                                // CHECK: xor <4 x i32>

  /* vec_or */
  res_vsc = vec_or(vsc, vsc);                   // CHECK: or <16 x i8>
  res_vuc = vec_or(vuc, vuc);                   // CHECK: or <16 x i8>
  res_vs  = vec_or(vs, vs);                     // CHECK: or <8 x i16>
  res_vus = vec_or(vus, vus);                   // CHECK: or <8 x i16>
  res_vi  = vec_or(vi, vi);                     // CHECK: or <4 x i32>
  res_vui = vec_or(vui, vui);                   // CHECK: or <4 x i32>
  res_vf  = vec_or(vf, vf);                     // CHECK: or <4 x i32>
  res_vsc = vec_vor(vsc, vsc);                  // CHECK: or <16 x i8>
  res_vuc = vec_vor(vuc, vuc);                  // CHECK: or <16 x i8>
  res_vs  = vec_vor(vs, vs);                    // CHECK: or <8 x i16>
  res_vus = vec_vor(vus, vus);                  // CHECK: or <8 x i16>
  res_vi  = vec_vor(vi, vi);                    // CHECK: or <4 x i32>
  res_vui = vec_vor(vui, vui);                  // CHECK: or <4 x i32>
  res_vf  = vec_vor(vf, vf);                    // CHECK: or <4 x i32>

  /* vec_pack */
  res_vsc = vec_pack(vs, vs);                   // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_pack(vus, vus);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_pack(vi, vi);                   // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_pack(vui, vui);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vsc = vec_vpkuhum(vs, vs);                // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_vpkuhum(vus, vus);              // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_vpkuwum(vi, vi);                // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_vpkuwum(vui, vui);              // CHECK: @llvm.ppc.altivec.vperm

  /* vec_packpx */
  res_vp = vec_packpx(vui, vui);                // CHECK: @llvm.ppc.altivec.vpkpx
  res_vp = vec_vpkpx(vui, vui);                 // CHECK: @llvm.ppc.altivec.vpkpx

  /* vec_packs */
  res_vsc = vec_packs(vs, vs);                  // CHECK: @llvm.ppc.altivec.vpkshss
  res_vuc = vec_packs(vus, vus);                // CHECK: @llvm.ppc.altivec.vpkuhus
  res_vs  = vec_packs(vi, vi);                  // CHECK: @llvm.ppc.altivec.vpkswss
  res_vus = vec_packs(vui, vui);                // CHECK: @llvm.ppc.altivec.vpkuwus
  res_vsc = vec_vpkshss(vs, vs);                // CHECK: @llvm.ppc.altivec.vpkshss
  res_vuc = vec_vpkuhus(vus, vus);              // CHECK: @llvm.ppc.altivec.vpkuhus
  res_vs  = vec_vpkswss(vi, vi);                // CHECK: @llvm.ppc.altivec.vpkswss
  res_vus = vec_vpkuwus(vui, vui);              // CHECK: @llvm.ppc.altivec.vpkuwus

  /* vec_packsu */
  res_vuc = vec_packsu(vs, vs);                 // CHECK: @llvm.ppc.altivec.vpkshus
  res_vuc = vec_packsu(vus, vus);               // CHECK: @llvm.ppc.altivec.vpkuhus
  res_vus = vec_packsu(vi, vi);                 // CHECK: @llvm.ppc.altivec.vpkswus
  res_vus = vec_packsu(vui, vui);               // CHECK: @llvm.ppc.altivec.vpkuwus
  res_vuc = vec_vpkshus(vs, vs);                // CHECK: @llvm.ppc.altivec.vpkshus
  res_vuc = vec_vpkshus(vus, vus);              // CHECK: @llvm.ppc.altivec.vpkuhus
  res_vus = vec_vpkswus(vi, vi);                // CHECK: @llvm.ppc.altivec.vpkswus
  res_vus = vec_vpkswus(vui, vui);              // CHECK: @llvm.ppc.altivec.vpkuwus

  /* vec_perm */
  res_vsc = vec_perm(vsc, vsc, vuc);            // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_perm(vuc, vuc, vuc);            // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_perm(vs, vs, vuc);              // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_perm(vus, vus, vuc);            // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_perm(vi, vi, vuc);              // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_perm(vui, vui, vuc);            // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_perm(vf, vf, vuc);              // CHECK: @llvm.ppc.altivec.vperm
  res_vsc = vec_vperm(vsc, vsc, vuc);           // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_vperm(vuc, vuc, vuc);           // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_vperm(vs, vs, vuc);             // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_vperm(vus, vus, vuc);           // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_vperm(vi, vi, vuc);             // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_vperm(vui, vui, vuc);           // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_vperm(vf, vf, vuc);             // CHECK: @llvm.ppc.altivec.vperm

  /* vec_re */
  res_vf = vec_re(vf);                          // CHECK: @llvm.ppc.altivec.vrefp
  res_vf = vec_vrefp(vf);                       // CHECK: @llvm.ppc.altivec.vrefp

  /* vec_rl */
  res_vsc = vec_rl(vsc, vuc);                   // CHECK: @llvm.ppc.altivec.vrlb
  res_vuc = vec_rl(vuc, vuc);                   // CHECK: @llvm.ppc.altivec.vrlb
  res_vs  = vec_rl(vs, vus);                    // CHECK: @llvm.ppc.altivec.vrlh
  res_vus = vec_rl(vus, vus);                   // CHECK: @llvm.ppc.altivec.vrlh
  res_vi  = vec_rl(vi, vui);                    // CHECK: @llvm.ppc.altivec.vrlw
  res_vui = vec_rl(vui, vui);                   // CHECK: @llvm.ppc.altivec.vrlw
  res_vsc = vec_vrlb(vsc, vuc);                 // CHECK: @llvm.ppc.altivec.vrlb
  res_vuc = vec_vrlb(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vrlb
  res_vs  = vec_vrlh(vs, vus);                  // CHECK: @llvm.ppc.altivec.vrlh
  res_vus = vec_vrlh(vus, vus);                 // CHECK: @llvm.ppc.altivec.vrlh
  res_vi  = vec_vrlw(vi, vui);                  // CHECK: @llvm.ppc.altivec.vrlw
  res_vui = vec_vrlw(vui, vui);                 // CHECK: @llvm.ppc.altivec.vrlw

  /* vec_round */
  res_vf = vec_round(vf);                       // CHECK: @llvm.ppc.altivec.vrfin
  res_vf = vec_vrfin(vf);                       // CHECK: @llvm.ppc.altivec.vrfin

  /* vec_rsqrte */
  res_vf = vec_rsqrte(vf);                      // CHECK: @llvm.ppc.altivec.vrsqrtefp
  res_vf = vec_vrsqrtefp(vf);                   // CHECK: @llvm.ppc.altivec.vrsqrtefp

  /* vec_sel */
  res_vsc = vec_sel(vsc, vsc, vuc);             // CHECK: xor <16 x i8>
                                                // CHECK: and <16 x i8>
                                                // CHECK: and <16 x i8>
                                                // CHECK: or <16 x i8>

  res_vuc = vec_sel(vuc, vuc, vuc);             // CHECK: xor <16 x i8>
                                                // CHECK: and <16 x i8>
                                                // CHECK: and <16 x i8>
                                                // CHECK: or <16 x i8>

  res_vs  = vec_sel(vs, vs, vus);               // CHECK: xor <8 x i16>
                                                // CHECK: and <8 x i16>
                                                // CHECK: and <8 x i16>
                                                // CHECK: or <8 x i16>


  res_vus = vec_sel(vus, vus, vus);             // CHECK: xor <8 x i16>
                                                // CHECK: and <8 x i16>
                                                // CHECK: and <8 x i16>
                                                // CHECK: or <8 x i16>

  res_vi  = vec_sel(vi, vi, vui);               // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: or <4 x i32>


  res_vui = vec_sel(vui, vui, vui);             // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: or <4 x i32>


  res_vf  = vec_sel(vf, vf, vui);               // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: or <4 x i32>

  res_vsc = vec_vsel(vsc, vsc, vuc);            // CHECK: xor <16 x i8>
                                                // CHECK: and <16 x i8>
                                                // CHECK: and <16 x i8>
                                                // CHECK: or <16 x i8>

  res_vuc = vec_vsel(vuc, vuc, vuc);            // CHECK: xor <16 x i8>
                                                // CHECK: and <16 x i8>
                                                // CHECK: and <16 x i8>
                                                // CHECK: or <16 x i8>

  res_vs  = vec_vsel(vs, vs, vus);              // CHECK: xor <8 x i16>
                                                // CHECK: and <8 x i16>
                                                // CHECK: and <8 x i16>
                                                // CHECK: or <8 x i16>


  res_vus = vec_vsel(vus, vus, vus);            // CHECK: xor <8 x i16>
                                                // CHECK: and <8 x i16>
                                                // CHECK: and <8 x i16>
                                                // CHECK: or <8 x i16>

  res_vi  = vec_vsel(vi, vi, vui);              // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: or <4 x i32>


  res_vui = vec_vsel(vui, vui, vui);            // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: or <4 x i32>


  res_vf  = vec_vsel(vf, vf, vui);              // CHECK: xor <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: and <4 x i32>
                                                // CHECK: or <4 x i32>


  /* vec_sl */
  res_vsc = vec_sl(vsc, vuc);                   // CHECK: shl <16 x i8>
  res_vuc = vec_sl(vuc, vuc);                   // CHECK: shl <16 x i8>
  res_vs  = vec_sl(vs, vus);                    // CHECK: shl <8 x i16>
  res_vus = vec_sl(vus, vus);                   // CHECK: shl <8 x i16>
  res_vi  = vec_sl(vi, vui);                    // CHECK: shl <4 x i32>
  res_vui = vec_sl(vui, vui);                   // CHECK: shl <4 x i32>
  res_vsc = vec_vslb(vsc, vuc);                 // CHECK: shl <16 x i8>
  res_vuc = vec_vslb(vuc, vuc);                 // CHECK: shl <16 x i8>
  res_vs  = vec_vslh(vs, vus);                  // CHECK: shl <8 x i16>
  res_vus = vec_vslh(vus, vus);                 // CHECK: shl <8 x i16>
  res_vi  = vec_vslw(vi, vui);                  // CHECK: shl <4 x i32>
  res_vui = vec_vslw(vui, vui);                 // CHECK: shl <4 x i32>

  /* vec_sld */
  res_vsc = vec_sld(vsc, vsc, 0);               // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_sld(vuc, vuc, 0);               // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_sld(vs, vs, 0);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_sld(vus, vus, 0);               // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_sld(vi, vi, 0);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_sld(vui, vui, 0);               // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_sld(vf, vf, 0);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vsc = vec_vsldoi(vsc, vsc, 0);            // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_vsldoi(vuc, vuc, 0);            // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_vsldoi(vs, vs, 0);              // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_vsldoi(vus, vus, 0);            // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_vsldoi(vi, vi, 0);              // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_vsldoi(vui, vui, 0);            // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_vsldoi(vf, vf, 0);              // CHECK: @llvm.ppc.altivec.vperm

  /* vec_sll */
  res_vsc = vec_sll(vsc, vuc);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vsc = vec_sll(vsc, vus);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vsc = vec_sll(vsc, vui);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vuc = vec_sll(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vuc = vec_sll(vuc, vus);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vuc = vec_sll(vuc, vui);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vs  = vec_sll(vs, vuc);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vs  = vec_sll(vs, vus);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vs  = vec_sll(vs, vui);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vus = vec_sll(vus, vuc);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vus = vec_sll(vus, vus);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vus = vec_sll(vus, vui);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vi  = vec_sll(vi, vuc);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vi  = vec_sll(vi, vus);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vi  = vec_sll(vi, vui);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vui = vec_sll(vui, vuc);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vui = vec_sll(vui, vus);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vui = vec_sll(vui, vui);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vsc = vec_vsl(vsc, vuc);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vsc = vec_vsl(vsc, vus);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vsc = vec_vsl(vsc, vui);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vuc = vec_vsl(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vuc = vec_vsl(vuc, vus);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vuc = vec_vsl(vuc, vui);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vs  = vec_vsl(vs, vuc);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vs  = vec_vsl(vs, vus);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vs  = vec_vsl(vs, vui);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vus = vec_vsl(vus, vuc);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vus = vec_vsl(vus, vus);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vus = vec_vsl(vus, vui);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vi  = vec_vsl(vi, vuc);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vi  = vec_vsl(vi, vus);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vi  = vec_vsl(vi, vui);                   // CHECK: @llvm.ppc.altivec.vsl
  res_vui = vec_vsl(vui, vuc);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vui = vec_vsl(vui, vus);                  // CHECK: @llvm.ppc.altivec.vsl
  res_vui = vec_vsl(vui, vui);                  // CHECK: @llvm.ppc.altivec.vsl

  /* vec_slo */
  res_vsc = vec_slo(vsc, vsc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vsc = vec_slo(vsc, vuc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vuc = vec_slo(vuc, vsc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vuc = vec_slo(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vs  = vec_slo(vs, vsc);                   // CHECK: @llvm.ppc.altivec.vslo
  res_vs  = vec_slo(vs, vuc);                   // CHECK: @llvm.ppc.altivec.vslo
  res_vus = vec_slo(vus, vsc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vus = vec_slo(vus, vuc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vi  = vec_slo(vi, vsc);                   // CHECK: @llvm.ppc.altivec.vslo
  res_vi  = vec_slo(vi, vuc);                   // CHECK: @llvm.ppc.altivec.vslo
  res_vui = vec_slo(vui, vsc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vui = vec_slo(vui, vuc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vf  = vec_slo(vf, vsc);                   // CHECK: @llvm.ppc.altivec.vslo
  res_vf  = vec_slo(vf, vuc);                   // CHECK: @llvm.ppc.altivec.vslo
  res_vsc = vec_vslo(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vslo
  res_vsc = vec_vslo(vsc, vuc);                 // CHECK: @llvm.ppc.altivec.vslo
  res_vuc = vec_vslo(vuc, vsc);                 // CHECK: @llvm.ppc.altivec.vslo
  res_vuc = vec_vslo(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vslo
  res_vs  = vec_vslo(vs, vsc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vs  = vec_vslo(vs, vuc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vus = vec_vslo(vus, vsc);                 // CHECK: @llvm.ppc.altivec.vslo
  res_vus = vec_vslo(vus, vuc);                 // CHECK: @llvm.ppc.altivec.vslo
  res_vi  = vec_vslo(vi, vsc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vi  = vec_vslo(vi, vuc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vui = vec_vslo(vui, vsc);                 // CHECK: @llvm.ppc.altivec.vslo
  res_vui = vec_vslo(vui, vuc);                 // CHECK: @llvm.ppc.altivec.vslo
  res_vf  = vec_vslo(vf, vsc);                  // CHECK: @llvm.ppc.altivec.vslo
  res_vf  = vec_vslo(vf, vuc);                  // CHECK: @llvm.ppc.altivec.vslo

  /* vec_splat */
  res_vsc = vec_splat(vsc, 0);                  // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_splat(vuc, 0);                  // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_splat(vs, 0);                   // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_splat(vus, 0);                  // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_splat(vi, 0);                   // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_splat(vui, 0);                  // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_splat(vf, 0);                   // CHECK: @llvm.ppc.altivec.vperm
  res_vsc = vec_vspltb(vsc, 0);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vuc = vec_vspltb(vuc, 0);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vs  = vec_vsplth(vs, 0);                  // CHECK: @llvm.ppc.altivec.vperm
  res_vus = vec_vsplth(vus, 0);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vi  = vec_vspltw(vi, 0);                  // CHECK: @llvm.ppc.altivec.vperm
  res_vui = vec_vspltw(vui, 0);                 // CHECK: @llvm.ppc.altivec.vperm
  res_vf  = vec_vspltw(vf, 0);                  // CHECK: @llvm.ppc.altivec.vperm

  /* vec_splat_s8 */
  res_vsc = vec_splat_s8(0x09);                 // TODO: add check
  res_vsc = vec_vspltisb(0x09);                 // TODO: add check

  /* vec_splat_s16 */
  res_vs = vec_splat_s16(0x09);                 // TODO: add check
  res_vs = vec_vspltish(0x09);                  // TODO: add check

  /* vec_splat_s32 */
  res_vi = vec_splat_s32(0x09);                 // TODO: add check
  res_vi = vec_vspltisw(0x09);                  // TODO: add check

  /* vec_splat_u8 */
  res_vuc = vec_splat_u8(0x09);                 // TODO: add check

  /* vec_splat_u16 */
  res_vus = vec_splat_u16(0x09);                // TODO: add check

  /* vec_splat_u32 */
  res_vui = vec_splat_u32(0x09);                // TODO: add check

  /* vec_sr */
  res_vsc = vec_sr(vsc, vuc);                   // CHECK: shr <16 x i8>
  res_vuc = vec_sr(vuc, vuc);                   // CHECK: shr <16 x i8>
  res_vs  = vec_sr(vs, vus);                    // CHECK: shr <8 x i16>
  res_vus = vec_sr(vus, vus);                   // CHECK: shr <8 x i16>
  res_vi  = vec_sr(vi, vui);                    // CHECK: shr <4 x i32>
  res_vui = vec_sr(vui, vui);                   // CHECK: shr <4 x i32>
  res_vsc = vec_vsrb(vsc, vuc);                 // CHECK: shr <16 x i8>
  res_vuc = vec_vsrb(vuc, vuc);                 // CHECK: shr <16 x i8>
  res_vs  = vec_vsrh(vs, vus);                  // CHECK: shr <8 x i16>
  res_vus = vec_vsrh(vus, vus);                 // CHECK: shr <8 x i16>
  res_vi  = vec_vsrw(vi, vui);                  // CHECK: shr <4 x i32>
  res_vui = vec_vsrw(vui, vui);                 // CHECK: shr <4 x i32>

  /* vec_sra */
  res_vsc = vec_sra(vsc, vuc);                  // CHECK: @llvm.ppc.altivec.vsrab
  res_vuc = vec_sra(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vsrab
  res_vs  = vec_sra(vs, vus);                   // CHECK: @llvm.ppc.altivec.vsrah
  res_vus = vec_sra(vus, vus);                  // CHECK: @llvm.ppc.altivec.vsrah
  res_vi  = vec_sra(vi, vui);                   // CHECK: @llvm.ppc.altivec.vsraw
  res_vui = vec_sra(vui, vui);                  // CHECK: @llvm.ppc.altivec.vsraw
  res_vsc = vec_vsrab(vsc, vuc);                // CHECK: @llvm.ppc.altivec.vsrab
  res_vuc = vec_vsrab(vuc, vuc);                // CHECK: @llvm.ppc.altivec.vsrab
  res_vs  = vec_vsrah(vs, vus);                 // CHECK: @llvm.ppc.altivec.vsrah
  res_vus = vec_vsrah(vus, vus);                // CHECK: @llvm.ppc.altivec.vsrah
  res_vi  = vec_vsraw(vi, vui);                 // CHECK: @llvm.ppc.altivec.vsraw
  res_vui = vec_vsraw(vui, vui);                // CHECK: @llvm.ppc.altivec.vsraw

  /* vec_srl */
  res_vsc = vec_srl(vsc, vuc);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vsc = vec_srl(vsc, vus);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vsc = vec_srl(vsc, vui);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vuc = vec_srl(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vuc = vec_srl(vuc, vus);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vuc = vec_srl(vuc, vui);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vs  = vec_srl(vs, vuc);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vs  = vec_srl(vs, vus);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vs  = vec_srl(vs, vui);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vus = vec_srl(vus, vuc);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vus = vec_srl(vus, vus);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vus = vec_srl(vus, vui);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vi  = vec_srl(vi, vuc);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vi  = vec_srl(vi, vus);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vi  = vec_srl(vi, vui);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vui = vec_srl(vui, vuc);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vui = vec_srl(vui, vus);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vui = vec_srl(vui, vui);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vsc = vec_vsr(vsc, vuc);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vsc = vec_vsr(vsc, vus);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vsc = vec_vsr(vsc, vui);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vuc = vec_vsr(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vuc = vec_vsr(vuc, vus);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vuc = vec_vsr(vuc, vui);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vs  = vec_vsr(vs, vuc);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vs  = vec_vsr(vs, vus);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vs  = vec_vsr(vs, vui);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vus = vec_vsr(vus, vuc);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vus = vec_vsr(vus, vus);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vus = vec_vsr(vus, vui);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vi  = vec_vsr(vi, vuc);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vi  = vec_vsr(vi, vus);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vi  = vec_vsr(vi, vui);                   // CHECK: @llvm.ppc.altivec.vsr
  res_vui = vec_vsr(vui, vuc);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vui = vec_vsr(vui, vus);                  // CHECK: @llvm.ppc.altivec.vsr
  res_vui = vec_vsr(vui, vui);                  // CHECK: @llvm.ppc.altivec.vsr

  /* vec_sro */
  res_vsc = vec_sro(vsc, vsc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vsc = vec_sro(vsc, vuc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vuc = vec_sro(vuc, vsc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vuc = vec_sro(vuc, vuc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vs  = vec_sro(vs, vsc);                   // CHECK: @llvm.ppc.altivec.vsro
  res_vs  = vec_sro(vs, vuc);                   // CHECK: @llvm.ppc.altivec.vsro
  res_vus = vec_sro(vus, vsc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vus = vec_sro(vus, vuc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vi  = vec_sro(vi, vsc);                   // CHECK: @llvm.ppc.altivec.vsro
  res_vi  = vec_sro(vi, vuc);                   // CHECK: @llvm.ppc.altivec.vsro
  res_vui = vec_sro(vui, vsc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vui = vec_sro(vui, vuc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vf  = vec_sro(vf, vsc);                   // CHECK: @llvm.ppc.altivec.vsro
  res_vf  = vec_sro(vf, vuc);                   // CHECK: @llvm.ppc.altivec.vsro
  res_vsc = vec_vsro(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vsro
  res_vsc = vec_vsro(vsc, vuc);                 // CHECK: @llvm.ppc.altivec.vsro
  res_vuc = vec_vsro(vuc, vsc);                 // CHECK: @llvm.ppc.altivec.vsro
  res_vuc = vec_vsro(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vsro
  res_vs  = vec_vsro(vs, vsc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vs  = vec_vsro(vs, vuc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vus = vec_vsro(vus, vsc);                 // CHECK: @llvm.ppc.altivec.vsro
  res_vus = vec_vsro(vus, vuc);                 // CHECK: @llvm.ppc.altivec.vsro
  res_vi  = vec_vsro(vi, vsc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vi  = vec_vsro(vi, vuc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vui = vec_vsro(vui, vsc);                 // CHECK: @llvm.ppc.altivec.vsro
  res_vui = vec_vsro(vui, vuc);                 // CHECK: @llvm.ppc.altivec.vsro
  res_vf  = vec_vsro(vf, vsc);                  // CHECK: @llvm.ppc.altivec.vsro
  res_vf  = vec_vsro(vf, vuc);                  // CHECK: @llvm.ppc.altivec.vsro

  /* vec_st */
  vec_st(vsc, 0, &vsc);                        // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vsc, 0, &param_sc);                   // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vuc, 0, &vuc);                        // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vuc, 0, &param_uc);                   // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vs, 0, &vs);                          // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vs, 0, &param_s);                     // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vus, 0, &vus);                        // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vus, 0, &param_us);                   // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vi, 0, &vi);                          // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vi, 0, &param_i);                     // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vui, 0, &vui);                        // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vui, 0, &param_ui);                   // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vf, 0, &vf);                          // CHECK: @llvm.ppc.altivec.stvx
  vec_st(vf, 0, &param_f);                     // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vsc, 0, &vsc);                      // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vsc, 0, &param_sc);                 // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vuc, 0, &vuc);                      // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vuc, 0, &param_uc);                 // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vs, 0, &vs);                        // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vs, 0, &param_s);                   // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vus, 0, &vus);                      // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vus, 0, &param_us);                 // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vi, 0, &vi);                        // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vi, 0, &param_i);                   // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vui, 0, &vui);                      // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vui, 0, &param_ui);                 // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vf, 0, &vf);                        // CHECK: @llvm.ppc.altivec.stvx
  vec_stvx(vf, 0, &param_f);                   // CHECK: @llvm.ppc.altivec.stvx

  /* vec_ste */
  vec_ste(vsc, 0, &param_sc);                  // CHECK: @llvm.ppc.altivec.stvebx
  vec_ste(vuc, 0, &param_uc);                  // CHECK: @llvm.ppc.altivec.stvebx
  vec_ste(vs, 0, &param_s);                    // CHECK: @llvm.ppc.altivec.stvehx
  vec_ste(vus, 0, &param_us);                  // CHECK: @llvm.ppc.altivec.stvehx
  vec_ste(vi, 0, &param_i);                    // CHECK: @llvm.ppc.altivec.stvewx
  vec_ste(vui, 0, &param_ui);                  // CHECK: @llvm.ppc.altivec.stvewx
  vec_ste(vf, 0, &param_f);                    // CHECK: @llvm.ppc.altivec.stvewx
  vec_stvebx(vsc, 0, &param_sc);               // CHECK: @llvm.ppc.altivec.stvebx
  vec_stvebx(vuc, 0, &param_uc);               // CHECK: @llvm.ppc.altivec.stvebx
  vec_stvehx(vs, 0, &param_s);                 // CHECK: @llvm.ppc.altivec.stvehx
  vec_stvehx(vus, 0, &param_us);               // CHECK: @llvm.ppc.altivec.stvehx
  vec_stvewx(vi, 0, &param_i);                 // CHECK: @llvm.ppc.altivec.stvewx
  vec_stvewx(vui, 0, &param_ui);               // CHECK: @llvm.ppc.altivec.stvewx
  vec_stvewx(vf, 0, &param_f);                 // CHECK: @llvm.ppc.altivec.stvewx

  /* vec_stl */
  vec_stl(vsc, 0, &vsc);                        // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vsc, 0, &param_sc);                   // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vuc, 0, &vuc);                        // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vuc, 0, &param_uc);                   // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vs, 0, &vs);                          // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vs, 0, &param_s);                     // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vus, 0, &vus);                        // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vus, 0, &param_us);                   // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vi, 0, &vi);                          // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vi, 0, &param_i);                     // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vui, 0, &vui);                        // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vui, 0, &param_ui);                   // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vf, 0, &vf);                          // CHECK: @llvm.ppc.altivec.stvxl
  vec_stl(vf, 0, &param_f);                     // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vsc, 0, &vsc);                      // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vsc, 0, &param_sc);                 // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vuc, 0, &vuc);                      // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vuc, 0, &param_uc);                 // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vs, 0, &vs);                        // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vs, 0, &param_s);                   // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vus, 0, &vus);                      // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vus, 0, &param_us);                 // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vi, 0, &vi);                        // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vi, 0, &param_i);                   // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vui, 0, &vui);                      // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vui, 0, &param_ui);                 // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vf, 0, &vf);                        // CHECK: @llvm.ppc.altivec.stvxl
  vec_stvxl(vf, 0, &param_f);                   // CHECK: @llvm.ppc.altivec.stvxl

  /* vec_sub */
  res_vsc = vec_sub(vsc, vsc);                  // CHECK: sub nsw <16 x i8>
  res_vuc = vec_sub(vuc, vuc);                  // CHECK: sub <16 x i8>
  res_vs  = vec_sub(vs, vs);                    // CHECK: sub nsw <8 x i16>
  res_vus = vec_sub(vus, vus);                  // CHECK: sub <8 x i16>
  res_vi  = vec_sub(vi, vi);                    // CHECK: sub nsw <4 x i32>
  res_vui = vec_sub(vui, vui);                  // CHECK: sub <4 x i32>
  res_vf  = vec_sub(vf, vf);                    // CHECK: fsub <4 x float>
  res_vsc = vec_vsububm(vsc, vsc);              // CHECK: sub nsw <16 x i8>
  res_vuc = vec_vsububm(vuc, vuc);              // CHECK: sub <16 x i8>
  res_vs  = vec_vsubuhm(vs, vs);                // CHECK: sub nsw <8 x i16>
  res_vus = vec_vsubuhm(vus, vus);              // CHECK: sub <8 x i16>
  res_vi  = vec_vsubuwm(vi, vi);                // CHECK: sub nsw <4 x i32>
  res_vui = vec_vsubuwm(vui, vui);              // CHECK: sub <4 x i32>
  res_vf  = vec_vsubfp(vf, vf);                 // CHECK: fsub <4 x float>

  /* vec_subc */
  res_vui = vec_subc(vui, vui);                 // CHECK: @llvm.ppc.altivec.vsubcuw
  res_vui = vec_vsubcuw(vui, vui);              // CHECK: @llvm.ppc.altivec.vsubcuw

  /* vec_subs */
  res_vsc = vec_subs(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vsubsbs
  res_vuc = vec_subs(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vsububs
  res_vs  = vec_subs(vs, vs);                   // CHECK: @llvm.ppc.altivec.vsubshs
  res_vus = vec_subs(vus, vus);                 // CHECK: @llvm.ppc.altivec.vsubuhs
  res_vi  = vec_subs(vi, vi);                   // CHECK: @llvm.ppc.altivec.vsubsws
  res_vui = vec_subs(vui, vui);                 // CHECK: @llvm.ppc.altivec.vsubuws
  res_vsc = vec_vsubsbs(vsc, vsc);              // CHECK: @llvm.ppc.altivec.vsubsbs
  res_vuc = vec_vsububs(vuc, vuc);              // CHECK: @llvm.ppc.altivec.vsububs
  res_vs  = vec_vsubshs(vs, vs);                // CHECK: @llvm.ppc.altivec.vsubshs
  res_vus = vec_vsubuhs(vus, vus);              // CHECK: @llvm.ppc.altivec.vsubuhs
  res_vi  = vec_vsubsws(vi, vi);                // CHECK: @llvm.ppc.altivec.vsubsws
  res_vui = vec_vsubuws(vui, vui);              // CHECK: @llvm.ppc.altivec.vsubuws

  /* vec_sum4s */
  res_vi  = vec_sum4s(vsc, vi);                 // CHECK: @llvm.ppc.altivec.vsum4sbs
  res_vui = vec_sum4s(vuc, vui);                // CHECK: @llvm.ppc.altivec.vsum4ubs
  res_vi  = vec_sum4s(vs, vi);                  // CHECK: @llvm.ppc.altivec.vsum4shs
  res_vi  = vec_vsum4sbs(vsc, vi);              // CHECK: @llvm.ppc.altivec.vsum4sbs
  res_vui = vec_vsum4ubs(vuc, vui);             // CHECK: @llvm.ppc.altivec.vsum4ubs
  res_vi  = vec_vsum4shs(vs, vi);               // CHECK: @llvm.ppc.altivec.vsum4shs

  /* vec_sum2s */
  res_vi = vec_sum2s(vi, vi);                   // CHECK: @llvm.ppc.altivec.vsum2sws
  res_vi = vec_vsum2sws(vi, vi);                // CHECK: @llvm.ppc.altivec.vsum2sws

  /* vec_sums */
  res_vi = vec_sums(vi, vi);                    // CHECK: @llvm.ppc.altivec.vsumsws
  res_vi = vec_vsumsws(vi, vi);                 // CHECK: @llvm.ppc.altivec.vsumsws

  /* vec_trunc */
  res_vf = vec_trunc(vf);                       // CHECK: @llvm.ppc.altivec.vrfiz
  res_vf = vec_vrfiz(vf);                       // CHECK: @llvm.ppc.altivec.vrfiz

  /* vec_unpackh */
  res_vs = vec_unpackh(vsc);                    // CHECK: @llvm.ppc.altivec.vupkhsb
  res_vi = vec_unpackh(vs);                     // CHECK: @llvm.ppc.altivec.vupkhsh
  res_vs = vec_vupkhsb(vsc);                    // CHECK: @llvm.ppc.altivec.vupkhsb
  res_vi = vec_vupkhsh(vs);                     // CHECK: @llvm.ppc.altivec.vupkhsh

  /* vec_unpackl */
  res_vs = vec_unpackl(vsc);                    // CHECK: @llvm.ppc.altivec.vupklsb
  res_vi = vec_vupklsh(vs);                     // CHECK: @llvm.ppc.altivec.vupklsh
  res_vs = vec_vupklsb(vsc);                    // CHECK: @llvm.ppc.altivec.vupklsb
  res_vi = vec_vupklsh(vs);                     // CHECK: @llvm.ppc.altivec.vupklsh

  /* vec_xor */
  res_vsc = vec_xor(vsc, vsc);                  // CHECK: xor <16 x i8>
  res_vuc = vec_xor(vuc, vuc);                  // CHECK: xor <16 x i8>
  res_vs  = vec_xor(vs, vs);                    // CHECK: xor <8 x i16>
  res_vus = vec_xor(vus, vus);                  // CHECK: xor <8 x i16>
  res_vi  = vec_xor(vi, vi);                    // CHECK: xor <4 x i32>
  res_vui = vec_xor(vui, vui);                  // CHECK: xor <4 x i32>
  res_vf  = vec_xor(vf, vf);                    // CHECK: xor <4 x i32>
  res_vsc = vec_vxor(vsc, vsc);                 // CHECK: xor <16 x i8>
  res_vuc = vec_vxor(vuc, vuc);                 // CHECK: xor <16 x i8>
  res_vs  = vec_vxor(vs, vs);                   // CHECK: xor <8 x i16>
  res_vus = vec_vxor(vus, vus);                 // CHECK: xor <8 x i16>
  res_vi  = vec_vxor(vi, vi);                   // CHECK: xor <4 x i32>
  res_vui = vec_vxor(vui, vui);                 // CHECK: xor <4 x i32>
  res_vf  = vec_vxor(vf, vf);                   // CHECK: xor <4 x i32>

  /* ------------------------------ predicates -------------------------------------- */

  /*  vec_all_eq */
  res_i = vec_all_eq(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpequb.p
  res_i = vec_all_eq(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpequb.p
  res_i = vec_all_eq(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpequh.p
  res_i = vec_all_eq(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpequh.p
  res_i = vec_all_eq(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpequw.p
  res_i = vec_all_eq(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpequw.p
  res_i = vec_all_eq(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpeqfp.p

  /* vec_all_ge */
  res_i = vec_all_ge(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpgtsb.p
  res_i = vec_all_ge(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpgtub.p
  res_i = vec_all_ge(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpgtsh.p
  res_i = vec_all_ge(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpgtuh.p
  res_i = vec_all_ge(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpgtsw.p
  res_i = vec_all_ge(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpgtuw.p
  res_i = vec_all_ge(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpgefp.p

  /* vec_all_gt */
  res_i = vec_all_gt(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpgtsb.p
  res_i = vec_all_gt(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpgtub.p
  res_i = vec_all_gt(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpgtsh.p
  res_i = vec_all_gt(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpgtuh.p
  res_i = vec_all_gt(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpgtsw.p
  res_i = vec_all_gt(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpgtuw.p
  res_i = vec_all_gt(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpgtfp.p

  /* vec_all_in */
  res_i = vec_all_in(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpbfp.p

  /* vec_all_le */
  res_i = vec_all_le(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpgtsb.p
  res_i = vec_all_le(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpgtub.p
  res_i = vec_all_le(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpgtsh.p
  res_i = vec_all_le(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpgtuh.p
  res_i = vec_all_le(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpgtsw.p
  res_i = vec_all_le(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpgtuw.p
  res_i = vec_all_le(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpgefp.p

  /* vec_all_nan */
  res_i = vec_all_nan(vf);                      // CHECK: @llvm.ppc.altivec.vcmpeqfp.p

  /*  vec_all_ne */
  res_i = vec_all_ne(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpequb.p
  res_i = vec_all_ne(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpequb.p
  res_i = vec_all_ne(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpequh.p
  res_i = vec_all_ne(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpequh.p
  res_i = vec_all_ne(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpequw.p
  res_i = vec_all_ne(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpequw.p
  res_i = vec_all_ne(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpeqfp.p

  /* vec_all_nge */
  res_i = vec_all_nge(vf, vf);                  // CHECK: @llvm.ppc.altivec.vcmpgefp.p

  /* vec_all_ngt */
  res_i = vec_all_ngt(vf, vf);                  // CHECK: @llvm.ppc.altivec.vcmpgtfp.p

  /* vec_all_nle */
  res_i = vec_all_nle(vf, vf);                  // CHECK: @llvm.ppc.altivec.vcmpgefp.p

  /* vec_all_nlt */
  res_i = vec_all_nlt(vf, vf);                  // CHECK: @llvm.ppc.altivec.vcmpgtfp.p

  /* vec_all_numeric */
  res_i = vec_all_numeric(vf);                  // CHECK: @llvm.ppc.altivec.vcmpeqfp.p

  /*  vec_any_eq */
  res_i = vec_any_eq(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpequb.p
  res_i = vec_any_eq(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpequb.p
  res_i = vec_any_eq(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpequh.p
  res_i = vec_any_eq(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpequh.p
  res_i = vec_any_eq(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpequw.p
  res_i = vec_any_eq(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpequw.p
  res_i = vec_any_eq(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpeqfp.p

  /* vec_any_ge */
  res_i = vec_any_ge(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpgtsb.p
  res_i = vec_any_ge(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpgtub.p
  res_i = vec_any_ge(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpgtsh.p
  res_i = vec_any_ge(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpgtuh.p
  res_i = vec_any_ge(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpgtsw.p
  res_i = vec_any_ge(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpgtuw.p
  res_i = vec_any_ge(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpgefp.p

  /* vec_any_gt */
  res_i = vec_any_gt(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpgtsb.p
  res_i = vec_any_gt(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpgtub.p
  res_i = vec_any_gt(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpgtsh.p
  res_i = vec_any_gt(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpgtuh.p
  res_i = vec_any_gt(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpgtsw.p
  res_i = vec_any_gt(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpgtuw.p
  res_i = vec_any_gt(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpgtfp.p

  /* vec_any_le */
  res_i = vec_any_le(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpgtsb.p
  res_i = vec_any_le(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpgtub.p
  res_i = vec_any_le(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpgtsh.p
  res_i = vec_any_le(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpgtuh.p
  res_i = vec_any_le(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpgtsw.p
  res_i = vec_any_le(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpgtuw.p
  res_i = vec_any_le(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpgefp.p

  /* vec_any_lt */
  res_i = vec_any_lt(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpgtsb.p
  res_i = vec_any_lt(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpgtub.p
  res_i = vec_any_lt(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpgtsh.p
  res_i = vec_any_lt(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpgtuh.p
  res_i = vec_any_lt(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpgtsw.p
  res_i = vec_any_lt(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpgtuw.p
  res_i = vec_any_lt(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpgtfp.p

  /* vec_any_nan */
  res_i = vec_any_nan(vf);                      // CHECK: @llvm.ppc.altivec.vcmpeqfp.p

  /* vec_any_ne */
  res_i = vec_any_ne(vsc, vsc);                 // CHECK: @llvm.ppc.altivec.vcmpequb.p
  res_i = vec_any_ne(vuc, vuc);                 // CHECK: @llvm.ppc.altivec.vcmpequb.p
  res_i = vec_any_ne(vs, vs);                   // CHECK: @llvm.ppc.altivec.vcmpequh.p
  res_i = vec_any_ne(vus, vus);                 // CHECK: @llvm.ppc.altivec.vcmpequh.p
  res_i = vec_any_ne(vi, vi);                   // CHECK: @llvm.ppc.altivec.vcmpequw.p
  res_i = vec_any_ne(vui, vui);                 // CHECK: @llvm.ppc.altivec.vcmpequw.p
  res_i = vec_any_ne(vf, vf);                   // CHECK: @llvm.ppc.altivec.vcmpeqfp.p

  /* vec_any_nge */
  res_i = vec_any_nge(vf, vf);                  // CHECK: @llvm.ppc.altivec.vcmpgefp.p

  /* vec_any_ngt */
  res_i = vec_any_ngt(vf, vf);                  // CHECK: @llvm.ppc.altivec.vcmpgtfp.p

  /* vec_any_nle */
  res_i = vec_any_nle(vf, vf);                  // CHECK: @llvm.ppc.altivec.vcmpgefp.p

  /* vec_any_nlt */
  res_i = vec_any_nlt(vf, vf);                  // CHECK: @llvm.ppc.altivec.vcmpgtfp.p

  /* vec_any_numeric */
  res_i = vec_any_numeric(vf);                  // CHECK: @llvm.ppc.altivec.vcmpeqfp.p

  /* vec_any_out */
  res_i = vec_any_out(vf, vf);                  // CHECK: @llvm.ppc.altivec.vcmpbfp.p

  return 0;
}
