/*******************************************************
*
*Time:2013-10-16
*Project:ȫ��ָ�����
*Purpose:����ͼ��ȫ��ָ��
*Author:���̳�
*Copyright(c)2013�꣬wangjicheng11@163.com
*Describe:�ṩͼ��ȫ��ָ��
*******************************************************/


#ifndef GLOBALMETRICS_HH
#define GLOBALMETRICS_HH
#include <string>
using std::string;
/** 
* \file GlobalMetrics.h  
* @brief ͼ��ȫ��ָ�����
* 
* ���ڼ���ͼ��ȫ��ָ�� 
*/  

#include <gdal_priv.h>

namespace Metrics
{
	/** 
	* \class ȫ��ָ������࣬GlobalMetrics.h  
	* @brief ���ɷֱ任��Principal Component Analysis 
	* 
	*/
	const int EXE_OK = 1;
	const int EXE_WRONG = -1;
	class GlobalMetrics
	{

	public:
		/**
		 *@brief:���캯��,��ʼ���������
		 *@param fileName:Ӱ���ļ�
		 */
		GlobalMetrics(const char* fileName);
		/**
		 *@brief:��������
		 */
		~GlobalMetrics();
		/**
		 *@brief ���òο�Ӱ��
		 *@param r_filename �ο�Ӱ��·��
		 *@return �ɹ�����ExE_OK,ʧ�ܷ���EXE_ERROR
		 */
		int SetRefImage(const char* r_filename);
		/**
		 *@brief Test method
		 */
		int Test()
		{
			if (PreProcessData() == EXE_OK)
			{
				//double* xx = Gaussion_Function(1.5);
				return EXE_OK;
			}
			else
			{
				return EXE_WRONG;
			}

		}
		//Variable for some basic index

		/**
		 *@brief ��ȡÿ���ε�ƽ��ֵ
		 *@return ���ز��ξ�ֵ
		 */
		double* GetBandMean() const;
		/**
		 *@brief ��ȡÿ���εı�׼��
		 *@return ���ر�׼��
		 */
		double* GetBandStd() const;
		/**
		 *@brief ��ȡ������
		 *@return ���ز�����
		 */
		int GetBandCount() const;
		/**
		 *@brief ���ɸ�˹��
		 *@param sigma ���룬standard deviation!!!
		 *@param L,�˳��ȣ�Ĭ��Ϊ11����11������
		 *@return ��˹�˺���
		 */
		double* Gaussion_Function(double sigma,int L = 11) const;
		/**
		 *@brief һά�������
		 *@param filter ��˹һά��������
		 *@param in ����
		 *@param L ���
		 */
		double Convolve(double* filter,double* in,int L);

		/**
		 *@brief ���㵥��UIQI
		 *@param data ������(L*L)
		 *@param L ���С
		 *@return UIQI for image block
		 */
		double* GenerateUIQIperBlock(double* data_f,double* data_r,int L);
		/**
		 *@brief ���㵥��Q4
		 *@param data ������(L*L*bandcount)
		 *@param L ���С
		 *@return Q4 for image block
		 */
		double GenerateQ4perBlock(double* data_f,double* data_r,int L);

		
		/************************************************************************/
		/* ����ָ��                                                                     */
		/************************************************************************/
		/**
		 *@brief 1. ����ƽ���ݶ�AG��Average Gradient��,
		 *@return ����AGֵ
		 */
		double* GetAG() const;

		/**
		 *@brief 2. ��������Ӱ������ϵ��CC(Correlation Coefficient)
		 *@return CC per band
		 */
		double* GetCC() const;

		/**
		 *@brief 8. ���������MSE��Mean square error)
		 *@return MSE per band
		 */
		double* GetMSE();

		/**
		 *@brief 9. ����NLSE(normalised least square error)
		 *@return NLSE per band
		 */
		double* GetNLSE() const;

		/**
		 *@brief 10. Calculate PSNR (Peak signal-to-noise ratio)
		 *@return PSNR per band;
		 */
		double* GeneratePSNR();
		 /**
		 *@brief 11. Calculate Q4 (Quaternion theory-based quality index)
		 *@param L the size of block,default value is 10
		 *@return Q4 per band;
		 */
		double GenerateQ4(int L = 10);

		/**
		 *@brief 15. RASE(Relative average spectral error)
		 *@return A RASE for Image.Else Return -1.0 denote the Wrong Results.
		 */
		double GenerateRASE();
		/**
		 *@brief 16. RM(Relative shift in Mean)
		 *@return RM per band;
		 */
		double* GenerateRM();
		/**
		 *@brief 17. RMSE(Root of mean square error)
		 *@return RMSE per band;
		 */
		double* GenerateRMSE();

		/**
		 *@brief 19. SAM(Spectral angle mapper)
		 *@return SAM(Rad),  if Failure, return -1;
		 */
		double GenerateSAM();

		/**
		 *@brief 20. SD(Standard deviation)
		 *@return SD per band
		 */
		double* GetSD();
		/**
		 *@brief 21. SF(Spatial frequency)
		 *@return SF per band;
		 */
		double* GenerateSF() const;
		/**
		 *@brief 22. SNR(Signal-to-noise ratio)
		 *@return SNR per band;
		 */
		double* GenerateSNR() const;
		/**
		 *@brief 23.13. SSIM(Structure similarity index) And QILV(Quality index based on local variance)
		 *@param K1 ����C1�ĳ�����Ĭ��Ϊ0.01
		 *@param K2 ����C2�ĳ�����Ĭ��Ϊ0.03
		 *@param sigma ��˹��׼�Ĭ��Ϊ1.5
		 *@param L ��˹ƽ�����ڴ�С��Ĭ��Ϊ11
		 *@param Out_SSIMImage SSIM�ļ��������ʱδʵ�֣�
		 *@return SSIM per band And QILV per band: first bandCount value are SSIM and the last bandCount value 
					are  QILV per band
		 */
		double* GenerateSSIMAndQILV(double K1 = 0.01,double K2 = 0.03,
			double sigma=1.5,int L = 11,string Out_SSIMImage = "");
		/**
		 *@brief 25.UIQI (Universal image quality index)
		 *@param L the size of block,default value is 10
		 *@return UIQI per band;
		 */
		double* GenerateUIQI(int L = 10);
	//For Methods	
	private:
		/**
		 *@brief ����Ԥ��������ͼ����Ϣ��ͳ�Ƶ�
		 *@return ����ִ�гɹ����
		 */
		int PreProcessData();


	//For variables

	private:
		//CProcessBase* m_pProcess;
		const char* m_fileName;
		bool m_fileisOK;
		GDALDataset* m_dataset;
		int m_iBandCount;
		double* m_pBandMean;
		double* m_pBandStd;
		int m_iXsize;
		int m_iYsize;
		double* m_dMax;
		double* m_dMin;
		

		//Variables about RefImage
		const char* m_rfile;
		GDALDataset* m_prdataset;
		double* m_rmean;
		double* m_rstd;
		bool hasRefFile;

		//Variables for indexes
		double* V2_CC;
		bool hasV2_CC;

		double* V8_MSE;
		bool hasV8_MSE;

		
	};
}

#endif