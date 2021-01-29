#include <stdio.h>

void main() {
  unsigned char xu_lie_hao[12] = {
    0x40, 0x00, 0x2b, 0x00,
    0x13, 0x51, 0x39, 0x30,
    0x39, 0x35, 0x37, 0x38
  };                          //12个8位序列号，LCD屏幕序列号从左向右读
  unsigned char mima[8];
  unsigned int a, b, c, d; //a=12个8位序列号累加结果保留最低10位
			    //b=序列号最高8位+序列号最低8位
                           //c=序列号累加和保留最低10位+序列号最高8位+序列号最低8位  
  unsigned int mi_ma_biao[1024] = {
 0x25, 0xe6, 0xbc, 0x70, 
 0xf1, 0x6d, 0x05, 0x4c, 
 0x3b, 0xc8, 0xfb, 0x4a, 
 0x3b, 0x15, 0x65, 0xcc, 
 0xf8, 0xca, 0xa8, 0x26, 
 0x8f, 0xa8, 0x5b, 0x2e, 
 0x9d, 0xbb, 0x19, 0xd4, 
 0x49, 0xf1, 0xad, 0xa1, 
 0x21, 0x69, 0xe9, 0xc2, 
 0x54, 0xfd, 0x2f, 0x15, 
 0x20, 0x44, 0x7d, 0x93, 
 0xd4, 0x29, 0xd8, 0x86, 
 0x03, 0x67, 0x05, 0x86, 
 0x38, 0xeb, 0x5e, 0xc5, 
 0x5b, 0xca, 0x69, 0xf7, 
 0xee, 0x21, 0x37, 0xa3, 
 0xe2, 0xef, 0x28, 0xd0, 
 0xeb, 0x67, 0x56, 0x00, 
 0xd5, 0xbc, 0x11, 0x5f, 
 0xcd, 0xfb, 0x09, 0x2c, 
 0x1e, 0xba, 0xd3, 0xa6, 
 0x23, 0x34, 0x73, 0x15, 
 0x01, 0xf7, 0xe5, 0xcd, 
 0xe2, 0x62, 0xdd, 0xbf, 
 0x44, 0xf9, 0x3f, 0xfc, 
 0x26, 0x58, 0xbc, 0x53, 
 0x25, 0xf9, 0xd6, 0x39, 
 0x58, 0xd4, 0x43, 0x34, 
 0x40, 0xc6, 0x0c, 0xa2, 
 0xc8, 0x57, 0x28, 0xdc, 
 0x06, 0xe3, 0x9e, 0x1f, 
 0x70, 0x8d, 0x8f, 0xf1, 
 0x09, 0xb6, 0x91, 0xae, 
 0xe4, 0x69, 0x8a, 0x33, 
 0xbf, 0x07, 0x29, 0xe4, 
 0x66, 0x44, 0xf5, 0x4a, 
 0x9d, 0xf8, 0xdc, 0x7d, 
 0x84, 0x98, 0x4f, 0x33, 
 0x0c, 0xae, 0xfe, 0xd0, 
 0x69, 0x66, 0x36, 0x37, 
 0x14, 0xe9, 0x65, 0x2d, 
 0x90, 0x12, 0x32, 0x94, 
 0x8e, 0xc3, 0x97, 0x8c, 
 0xdc, 0xea, 0x6f, 0x96, 
 0x40, 0xe8, 0xa8, 0xe4, 
 0x19, 0x07, 0xde, 0x80, 
 0xd7, 0xe2, 0x35, 0xd5, 
 0xe0, 0x49, 0x2f, 0x15, 
 0xa2, 0x32, 0x24, 0xdf, 
 0x36, 0x16, 0xea, 0x86, 
 0xb3, 0x98, 0x64, 0x69, 
 0x22, 0xc9, 0x79, 0x4c, 
 0x09, 0xdd, 0xc5, 0x16, 
 0xd3, 0xfd, 0xec, 0xe4,  
 0x46, 0xaa, 0x6e, 0xed, 
 0x8a, 0xdd, 0x3c, 0x31, 
 0xf1, 0x95, 0x68, 0x61, 
 0xa9, 0x54, 0x25, 0x70, 
 0x40, 0x0d, 0xea, 0x8f, 
 0xad, 0x0b, 0x0d, 0xf4, 
 0x39, 0x8f, 0x65, 0x52, 
 0x58, 0x06, 0x6f, 0x23, 
 0x0a, 0x59, 0xb7, 0x56, 
 0x48, 0x9e, 0xa0, 0xc4, 
 0x3f, 0xf4, 0x2e, 0x6e, 
 0xe4, 0x4c, 0x67, 0xc4, 
 0x78, 0x47, 0x70, 0x12, 
 0xda, 0x00, 0xc0, 0xbe, 
 0x29, 0xc7, 0x9f, 0x6e, 
 0x14, 0xcd, 0xce, 0x50, 
 0xe0, 0x97, 0xf8, 0x72, 
 0x5e, 0xae, 0x6c, 0x1a, 
 0x6a, 0xb7, 0xfe, 0x1c, 
 0x70, 0x73, 0xd2, 0x34, 
 0x27, 0x89, 0x77, 0x89, 
 0x3d, 0x8d, 0x38, 0x4a, 
 0x75, 0x69, 0x16, 0x60, 
 0xb6, 0xb9, 0x05, 0x84, 
 0xed, 0xdd, 0x97, 0x90, 
 0x69, 0x57, 0xec, 0x6b, 
 0x71, 0xe1, 0x42, 0x8a, 
 0xdd, 0x24, 0xde, 0xa8, 
 0x82, 0x7f, 0x1d, 0xc2, 
 0xdb, 0x2c, 0x37, 0x14, 
 0x2a, 0x75, 0x2a, 0x0a, 
 0x98, 0x5c, 0x41, 0x11, 
 0x0a, 0x48, 0x39, 0x74, 
 0xd0, 0x79, 0x5f, 0x4b, 
 0xb6, 0x5f, 0x33, 0xd0, 
 0x24, 0xe0, 0x01, 0xcc, 
 0x9b, 0x7a, 0x71, 0x4d, 
 0x3a, 0x16, 0xb7, 0x65, 
 0xe7, 0x7e, 0x30, 0x59, 
 0x9b, 0x4d, 0xbc, 0x8a, 
 0x95, 0xd0, 0x57, 0x75, 
 0xf9, 0x5f, 0x03, 0x87, 
 0x37, 0xfe, 0x35, 0x18, 
 0xc1, 0xeb, 0x69, 0x01, 
 0x1d, 0xe0, 0xf7, 0xc0, 
 0xbe, 0xd4, 0xcf, 0x6b, 
 0x7f, 0x4b, 0xa2, 0xaa, 
 0x37, 0x2d, 0x64, 0x76, 
 0xd5, 0x32, 0x88, 0xdc, 
 0x2e, 0x70, 0x57, 0xcb, 
 0x30, 0xc0, 0x56, 0x54, 
 0xb0, 0xbb, 0x2d, 0x40, 
 0x4e, 0x63, 0x7c, 0xac, 
 0x67, 0xef, 0x4c, 0x1d, 
 0x54, 0x00, 0x79, 0x2c, 
 0x51, 0xe9, 0x25, 0x2f, 
 0x54, 0xbf, 0xaf, 0x76, 
 0x02, 0x42, 0x7c, 0xb9, 
 0xec, 0x97, 0x03, 0x18, 
 0xd8, 0xae, 0x32, 0x7c, 
 0x3d, 0x30, 0xd2, 0xd7, 
 0x64, 0xe3, 0xd5, 0x52, 
 0xbb, 0x37, 0x21, 0xb3, 
 0x65, 0x59, 0x7e, 0xd6, 
 0xf4, 0x05, 0xfc, 0xc7, 
 0xf7, 0xc4, 0xbf, 0x58, 
 0x93, 0xe4, 0x14, 0xf0, 
 0x0b, 0xff, 0xca, 0xe1, 
 0xd4, 0x77, 0x6e, 0x85, 
 0x57, 0x3f, 0xa1, 0xdc, 
 0x6f, 0x6a, 0x21, 0xce, 
 0xa0, 0xd3, 0xc1, 0xe8, 
 0x84, 0x1f, 0xab, 0x41, 
 0xf8, 0x42, 0xdc, 0x80, 
 0x0c, 0xba, 0x50, 0x77, 
 0x07, 0x68, 0xbf, 0xd4, 
 0xd0, 0x0b, 0x0b, 0xfa, 
 0x1f, 0x76, 0xaf, 0xd2, 
 0x6e, 0x92, 0x95, 0x37, 
 0x61, 0xa9, 0x7b, 0xe5, 
 0x49, 0xb3, 0xe7, 0x5d, 
 0xab, 0x77, 0x3c, 0xcb, 
 0x1e, 0x68, 0x8c, 0xbf, 
 0x46, 0xe8, 0xb5, 0xde, 
 0x37, 0x05, 0xb6, 0x6a, 
 0x2f, 0xf6, 0xf8, 0xc5, 
 0x9f, 0xf2, 0xd7, 0xb0, 
 0xe3, 0x87, 0x07, 0xaa, 
 0xfb, 0x2a, 0x5a, 0xd9, 
 0xad, 0x03, 0xd7, 0xda, 
 0xcd, 0x66, 0x33, 0x22, 
 0x54, 0x3e, 0x94, 0x1e, 
 0xab, 0xf0, 0x58, 0xc9, 
 0xa2, 0x5b, 0xc5, 0x82, 
 0x0c, 0x69, 0x0f, 0x52, 
 0xc3, 0xfa, 0x21, 0x50, 
 0xe7, 0xa4, 0x42, 0xa5, 
 0xc3, 0x61, 0x99, 0xbc, 
 0x2c, 0xc4, 0x14, 0xc3, 
 0x16, 0xb9, 0xc4, 0xa5, 
 0x26, 0x4d, 0x06, 0x10, 
 0x9c, 0xc8, 0x0e, 0x8f, 
 0x19, 0x5c, 0x99, 0x3f, 
 0x3a, 0xab, 0xe8, 0x09, 
 0x41, 0xf0, 0x51, 0x76, 
 0xe1, 0xf1, 0x61, 0xbd, 
 0x8a, 0x0d, 0xce, 0x91, 
 0x34, 0x7a, 0x58, 0xc0, 
 0x7c, 0x3e, 0x7d, 0xbe, 
 0x73, 0x24, 0xb8, 0x74, 
 0x0c, 0x7b, 0x52, 0x76, 
 0x5a, 0xed, 0xbf, 0xab, 
 0x56, 0x93, 0x23, 0x11, 
 0xd0, 0xf3, 0x64, 0xac, 
 0x46, 0xa0, 0x1a, 0xab, 
 0x67, 0x99, 0x7b, 0xd5, 
 0xa4, 0xcc, 0x3f, 0xa5, 
 0xfb, 0xea, 0xab, 0xf2, 
 0x19, 0x94, 0x11, 0x9c, 
 0xdb, 0x18, 0xf6, 0x7f, 
 0xbc, 0x21, 0x22, 0x29, 
 0xff, 0x8d, 0xaa, 0xb8, 
 0x46, 0x3f, 0x9e, 0x2f, 
 0x39, 0x29, 0x34, 0x36, 
 0x49, 0xd3, 0x6c, 0xe6, 
 0xc3, 0x55, 0x11, 0xbd, 
 0x15, 0x17, 0x0a, 0x36, 
 0x4e, 0x9c, 0xb3, 0x5a, 
 0x20, 0x57, 0x6a, 0xf7, 
 0xf7, 0x92, 0x55, 0x79, 
 0x95, 0x0a, 0xf3, 0x2c, 
 0x2c, 0xaf, 0x9c, 0xab, 
 0x1d, 0x6d, 0xe1, 0xe1, 
 0x72, 0x63, 0xc8, 0x05, 
 0x8a, 0x18, 0x74, 0xa1, 
 0x05, 0x42, 0xef, 0x87, 
 0x9f, 0x33, 0x34, 0x3a, 
 0xad, 0x9b, 0xae, 0x59, 
 0x67, 0xf7, 0xc2, 0x1e, 
 0xbc, 0xdb, 0xf2, 0x50, 
 0x50, 0x42, 0xca, 0x84, 
 0x63, 0xfe, 0xbc, 0xdf, 
 0xbc, 0xde, 0xd8, 0xf0, 
 0x64, 0x9a, 0x4c, 0xdf, 
 0xf8, 0x4c, 0x69, 0xf9, 
 0xee, 0x9f, 0xb9, 0x54, 
 0xf9, 0xdd, 0xce, 0x96, 
 0xe0, 0x8b, 0xb6, 0xd1, 
 0xa8, 0x88, 0xc2, 0x51, 
 0x5d, 0x9a, 0x4d, 0x72, 
 0x5a, 0x67, 0xea, 0xd6, 
 0x7a, 0x5e, 0x56, 0xa5, 
 0xb9, 0xde, 0x17, 0xc0, 
 0x5b, 0x6a, 0x26, 0xba, 
 0x3b, 0xee, 0x02, 0xd5, 
 0x16, 0x94, 0x47, 0x0f, 
 0x5f, 0xf0, 0x30, 0x9a, 
 0x8b, 0x01, 0xda, 0xc7, 
 0x32, 0xfa, 0xb5, 0x63, 
 0xb0, 0xa4, 0x50, 0x5f, 
 0x23, 0x89, 0x17, 0x7c, 
 0x7d, 0xa0, 0xab, 0xe5, 
 0x19, 0x48, 0x3b, 0x94, 
 0x3b, 0xcd, 0x2d, 0x55, 
 0xe5, 0x49, 0x5f, 0x8f, 
 0xab, 0x66, 0x40, 0x99, 
 0x14, 0x15, 0xeb, 0xf3, 
 0x23, 0xda, 0x69, 0x41, 
 0xc2, 0xf2, 0xdd, 0x0e, 
 0xc2, 0xda, 0xfe, 0x24, 
 0x83, 0xd4, 0x83, 0x98, 
 0xa5, 0x9a, 0x12, 0xb0, 
 0x4b, 0x2a, 0xc4, 0xb4, 
 0x3f, 0xf4, 0x88, 0x66, 
 0xf4, 0xc5, 0x24, 0x43, 
 0x5f, 0x7d, 0x2b, 0x42, 
 0xa9, 0x3b, 0xe5, 0x81, 
 0x96, 0x4b, 0x70, 0x20, 
 0x35, 0x9d, 0x00, 0x05, 
 0x94, 0xcc, 0x12, 0x56, 
 0xf8, 0x44, 0xaf, 0xa3, 
 0xa1, 0x8d, 0x2d, 0xbf, 
 0xd6, 0x21, 0x33, 0xa7, 
 0x70, 0x0f, 0xaf, 0x80, 
 0xdc, 0x0f, 0xec, 0xaf, 
 0x2d, 0x6e, 0x18, 0x0b, 
 0xb4, 0xf9, 0x43, 0xb0, 
 0x90, 0xe3, 0x64, 0xe0, 
 0xf4, 0x69, 0xf7, 0x0d, 
 0x9f, 0xcb, 0x0d, 0x29, 
 0x53, 0x86, 0xcf, 0x8e, 
 0x5b, 0xd3, 0x24, 0x2b, 
 0x0d, 0xec, 0x4e, 0xc9, 
 0x90, 0x38, 0xbd, 0x0e, 
 0x9b, 0x29, 0x49, 0xb7, 
 0x99, 0x66, 0xea, 0xf7, 
 0x6c, 0x6b, 0xf2, 0xda, 
 0x1c, 0x36, 0xa8, 0x42, 
 0xe0, 0x1b, 0x80, 0x3d, 
 0x05, 0xfd, 0x19, 0x09, 
 0x88, 0xa2, 0x54, 0x36, 
 0x9f, 0x31, 0x7f, 0xb4, 
 };
  for (int i = 0; i < 12; i = i + 1){
    d = xu_lie_hao[i];
    a = a + d;
  }
  a = a & 0x3ff;        //12个8位序列号累加后保留最低10位
  b = xu_lie_hao[0];    // b等于最低8位
  d = xu_lie_hao[11];   // d等于最高8位
  b = b +d;             // b等于最高8位加最低8位
  c = b + a;            // 最高8位+最低8位+累加后保留的最低10位
  
  
    for (int i = 0; i < 8; i = i + 1){
      mima[i] = mi_ma_biao[c];        
      c = (c + a) & 0x3ff;
    }
    printf("0x%02X  0x%02X  0x%02X  0x%02X  0x%02X  0x%02X  0x%02X  0x%02X \n",mima[0],mima[1],mima[2],mima[3],mima[4],mima[5],mima[6],mima[7]);
        
}
	
