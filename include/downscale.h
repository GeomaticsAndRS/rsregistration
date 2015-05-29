/*********************************************************************************
*
* Time: 2014-02-15
* Project: ���������²���
* Purpose: �Է������ݽ���Majority Aggregation������
* Author: ���̳�(Wang Jicheng, @Kevin)
* Copyright(c) 2014, wangjicheng11@163.com
* Describe: �ṩ�����е�Majority���á�
*
**********************************************************************************/

/**
* \file DownScale.h
* @brief ���������²���
*
*/
#ifndef DOWNSCALE__HH
#define DOWNSCALE__HH
#include <gdal_priv.h>
#include "param.h"

/**
* \class DownScale
* @describe Ӱ��߶�����
* @Initia DownScale new = new DownScale(file);
*/
class DownScale
{
public:

	/**
	* @brief ���캯��
	* @param pszSrcFile       ��ʼ���ļ�·��
	*/
	DownScale(const char* pszSrcFile);

	/**
	* @brief ��������
	*/
	~DownScale();
public:
	/**
	* @brief ִ������
	* @param pszOutFile        ����ļ�·��
	* @param msize             aggregate size
	* @return                  ִ�гɹ������
	*/
	int ExecuteAggregation(const char* pszOutFile,int msize);
	/**
	* @brief ִ�оۺ�
	* @param pszOutFile        ����ļ�·��
	* @param msize             aggregate size���������Ҫ���250��������Ϊ250��
	* @return                  ִ�гɹ������
	*/
	int ExecuteAggregationEx(const char* pszOutFile,int msize);

	/**
	* @brief ִ�о������ȼ�������
	* @param pszOutFile        ����ļ�·��
	* @param msize             aggregate size
	* @param option            ѡ����(1 Ĭ��)���߶��������ȼ��㷨
	* @return                  ִ�гɹ������
	*/
	int ExecuteAggregationWithPriority(const char* pszOutFile,int msize,int option);

	/**
	* @brief ִ������
	* @param pszOutFile        ����ļ�·��
	* @param msize             aggregate size
	* @param option            ѡ����(1 Ĭ��)���߶��������ȼ��㷨
	* @return                  ִ�гɹ������
	*/
	int ExecuteAggregationWithPriorityEx(const char* pszOutFile,int msize,int option);
	/**
	* @brief ִ��ƽ��������
	* @param pszOutFile        ����ļ�·��
	* @param msize             aggregate size
	* @param smoothwindowSize  smooth window size
	* @return                  ִ�гɹ������
	*/
	int ExecuteSmooth(const char* pszOutFile,int msize,int smoothwindowSize);

private:
	/**
	* @brief Ԥ�������ݣ���ȡ�ļ���Ϣ
	* @return                 ִ�гɹ������
	*/
	int PreProcessData();
	/**
	* @brief ��ȡ����
	* @return                 ���ݵ�һ���Σ�������󣬷���NULL
	*/
	Byte* ReadData();

	/**
	* @brief ִ�оۺϵ�Ԫ�������ۺϣ� ������ֱ��ʹ��Ӱ������ָ�룩
	* @param oi               ָ���ʼλ�ã���
	* @param oj               ָ���ʼλ�ã���
	* @param data             Ӱ������
	* @param msize            ��Ԫ��С��msize*msize
	* @return                 ���ؾۺϽ��
	*/
	Byte Marjority_Aggregation(int oi,int oj,Byte* data, int msize);

	//int Marjority_Aggregation();
	/**
	* @brief ִ������ƽ��
	* @param data             ����ָ�����飬������Ҫ�˲���
	* @param size             ��Ԫ��С
	* @param centerPriority   �м���ԪȨ��
	* @return                 ���ؾۺϽ��
	*/
	Byte Marjority_Smoothing(Byte** data, int size,int centerPriority);

	/**
	* @brief ִ�������ۺ���չ�������԰棬��������30m�ֱ��ʵľۺϣ�
	* @param oi              ����������Ӱ��λ������
	* @param oj              ����������Ӱ��λ��
	* @param data            �м�����
	* @param msize           ��Ԫ��С��msize*msize��250m�ķֱ��ʼ�25��
	*/
	Byte Marjority_AggregationEx(int oi,int oj,Byte* data, int msize);


	/**
	* @brief ִ�оۺϵ�Ԫ�������ۺϣ�������ֱ��ʹ��Ӱ������ָ�룩
	* @param oi               ָ���ʼλ�ã���
	* @param oj               ָ���ʼλ�ã���
	* @param data             Ӱ������
	* @param msize            ��Ԫ��С��msize*msize
	* @return                 ���ؾۺϽ��
	*/
	Byte Marjority_AggregationwithPriority1(int oi,int oj,Byte* data,int size);

	/**
	* @brief ִ�����ȼ������㷨��չ���԰�
	* @param oi
	* @param oj
	* @param data
	* @param msize
	* @return
	*/
	Byte Marjority_AggregationwithPriority1Ex(int oi,int oj,Byte* data,int size);
	/**
	* @brief ִ�оۺϵ�Ԫ�������ۺϣ�������ֱ��ʹ��Ӱ������ָ�룩,�����ȼ���������
	* @param oi               ָ���ʼλ�ã���
	* @param oj               ָ���ʼλ�ã���
	* @param data             Ӱ������
	* @param msize            ��Ԫ��С��msize*msize
	* @return                 ���ؾۺϽ��
	*/
	Byte Marjority_AggregationwithPriority2(int oi,int oj,Byte* data,int size);

	/**
	* @brief ִ�ж������ȼ��������ۺ���չ��
	* @param oi               ָ���ʼλ�ã���
	* @param oj               ָ���ʼλ�ã���
	* @param data             Ӱ������
	* @param msize            ��Ԫ��С��msize*msize
	* @return                 ���ؾۺϽ��
	*/
	Byte Marjority_AggregationwithPriority2Ex(int oi,int oj,Byte* data,int size);

	/**
	* @brief �����������С����
	* @param a                ��������
	* @param n				  �����������
	* @param id               ������ţ�Ĭ�ϣ�0,1,2,3.......��
	* @param m                ������Ҫ�����Ԫ�ظ�������ͷ��ʼ��
	*/
	void Sort(int* a,int n,int* id,int m);
private:
	const char* m_pszSrcFile;          /*<! ��Ҫ���в������ļ�·�� */
	//�ļ���Ϣ
	int m_iBandCount;                  /*<! ���θ��� */
	int m_iXsize;                      /*<! դ���� */
	int m_iYsize;                      /*<! դ��߶� */
	//int* m_pColor;                   /*<! ��ɫ���� */
	const char* m_projection;          /*<! ͶӰ��Ϣ */
	double* m_pGeoAffine;              /*<! 6��������� */
	GDALColorTable* m_pColorTable;     /*<! ��ɫ�� */
	bool m_isInitial;                  /*<! �Ƿ��ʼ������*/

	//double *m_pBandMean;             /*<! ���ξ�ֵ */
	//double *m_pBandStd;              /*<! ���ξ����� */
	GDALDataset *m_pSrcDS;             /*<! Դ�ļ�ָ�� */
};

struct MyStruct
{

};
#endif

