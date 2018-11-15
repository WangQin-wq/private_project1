#include"omlsa_def.h"
int FrameCnt = 1;


typedef  struct {
   omlsa_float32_t re;
   omlsa_float32_t im;
}creal_T;

//Ram A:  512*8 2K B = 257 *8 1K
//Num A:  10   5 + 6T    B:  42 + 15T  
//             10k 12k       42k + 15k        
omlsa_float32_t pcm[FRAME_LEN];            //  A  2k

omlsa_float32_t Sf[FRAME_LEN21+3];			//B
omlsa_float32_t S[FRAME_LEN21];				//B
omlsa_float32_t Smin[FRAME_LEN21];			//B
omlsa_float32_t Smact[FRAME_LEN21];			//B
omlsa_float32_t Sft[FRAME_LEN21];			//B
omlsa_float32_t St[FRAME_LEN21];			//B
omlsa_float32_t Smint[FRAME_LEN21];			//B
omlsa_float32_t Smactt[FRAME_LEN21];		//B
omlsa_float32_t Sy[FRAME_LEN21];			//B
omlsa_float32_t alpha_dt[FRAME_LEN21];		//B
omlsa_float32_t alpha_dt_long[FRAME_LEN21]; //B
omlsa_float32_t lambda_dav[FRAME_LEN21];	//B
omlsa_float32_t lambda_dt[FRAME_LEN21];		//B
omlsa_float32_t lambda_d_long[FRAME_LEN21];	//B
omlsa_float32_t eta[FRAME_LEN21];			//B
omlsa_float32_t eta_2term[FRAME_LEN21];		//B    18k
									  
omlsa_float32_t S_his0[FRAME_LEN21][8];		//8*B
omlsa_float32_t S_his[FRAME_LEN21][8];		//8*B   
omlsa_float32_t xi[FRAME_LEN21];			//B    35k

 
omlsa_float32_t xi_frame, ex_xi_frame, xi_frame_dB,P_frame;
omlsa_float32_t out_buf[FRAME_LEN];                //A

// win
omlsa_float32_t Window[FRAME_LEN];                 //A C
omlsa_float32_t Cwin= 0;
  



 
void ifft(const creal_T x[512], creal_T y[512]);	