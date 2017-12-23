#pragma once

namespace SOUI
{
#define SHDI_WIDTH               0x0001
#define SHDI_TEXT                0x0002
#define SHDI_SORTFLAG            0x0004
#define SHDI_LPARAM              0x0008
#define SHDI_ORDER               0x0010
#define SHDI_VISIBLE             0x0020

#define CX_HDITEM_MARGIN    4
	/**
	* @enum      _SHDSORTFLAG
	* @brief     �����־
	*
	* Describe   �����־
	*/
	// 	enum SHDSORTFLAG008 {
	// 		ST_NULL = 0,
	// 		ST_UP,
	// 		ST_DOWN,
	// 	};

		/**
		* @struct    _SHDITEM
		* @brief     �б�ͷ��
		*
		* Describe   �б�ͷ��
		*/
	typedef struct SHDITEM008 {
		SHDITEM008() :mask(0), cx(0), stFlag(ST_NULL), iOrder(0), bVisible(true) {
		}
		UINT    mask;
		int cx;
		SHDSORTFLAG stFlag;
		int     iOrder;
		bool    bVisible;
	}*LPSHDITEM008;


	/**
	* @class     SHeaderCtrl008
	* @brief     ��ͷ�ؼ�
	*
	* Describe   ��ͷ�ؼ�
	*/
	class SHeaderItem;
	class /*SOUI_EXP*/ SHeaderCtrl008 : public SWindow//, public ITimelineHandler
	{
		SOUI_CLASS_NAME(SHeaderCtrl008, L"header008")
			friend class SHeaderItem;
	public:
		/**
		* SHeaderCtrl008::SHeaderCtrl008
		* @brief    ���캯��
		*
		* Describe  ���캯��
		*/
		SHeaderCtrl008(void);
		/**
		* SHeaderCtrl008::~SHeaderCtrl008
		* @brief    ��������
		*
		* Describe  ��������
		*/
		~SHeaderCtrl008(void);

		/**
		* SHeaderCtrl008::InsertItem
		* @brief    ��������
		* @param    int iItem --  ��������
		* @param    LPCTSTR pszText  --  �������
		* @param    int nWidth  -- ���
		* @param    SHDSORTFLAG stFlag -- �����־
		* @param    LPARAM lParam -- ���Ӳ���
		* @return   ����int
		*
		* Describe  ��������
		*/
		//int InsertItem(int iItem, LPCTSTR pszText, int nWidth, SHDSORTFLAG stFlag, LPARAM lParam);
		//int InsertItem(int iItem, LPCTSTR pszText, int nWidth, SLayoutSize::Unit unit, SHDSORTFLAG stFlag, LPARAM lParam);
		/**
		* SHeaderCtrl008::GetItem
		* @brief    �������
		* @param    int iItem  --  ����
		* @param    SHDITEM *pItem  -- �����б���ṹ
		* @return   ����BOOL
		*
		* Describe  �������
		*/
		BOOL GetItem(int iItem, SHDITEM008 *pItem);

		/**
		* SHeaderCtrl008::GetItemCount
		* @brief    ��ȡ�б������
		* @return   ����int
		*
		* Describe  ��ȡ�б������
		*/
		size_t GetItemCount() const { return m_arrItems.GetCount(); }
		/**
		* SHeaderCtrl008::GetTotalWidth
		* @brief    ������п��
		* @return   ����int
		*
		* Describe  ������п��
		*/
		int GetTotalWidth();

		/**
		* SHeaderCtrl008::DeleteItem
		* @brief    ɾ��ָ����
		* @param    int iItem  --  ����
		* @return   ����BOOL
		*
		* Describe  ɾ��ָ����
		*/
		BOOL DeleteItem(int iItem);

		/**
		* SHeaderCtrl008::DeleteAllItems
		* @brief    ɾ��������
		*
		* Describe  �������
		*/
		void DeleteAllItems();

		void SetItemSort(int iItem, SHDSORTFLAG stFlag);

		void SetItemVisible(int iItem, bool visible);

		bool IsItemVisible(int iItem) const;

		SOUI_ATTRS_BEGIN()
			ATTR_SKIN(L"itemSkin", m_pSkinItem, FALSE)
			ATTR_SKIN(L"sortSkin", m_pSkinSort, FALSE)
			ATTR_INT(L"fixWidth", m_bFixWidth, FALSE)
			ATTR_INT(L"itemSwapEnable", m_bItemSwapEnable, FALSE)
			ATTR_INT(L"sortHeader", m_bSortHeader, FALSE)
		SOUI_ATTRS_END()
			
	protected:
//		virtual void OnNextFrame() override;
		int ChangeItemPos(SHeaderItem* pCurMove, CPoint ptCur);
		void ChangeItemSize(SHeaderItem*,CPoint ptCur);
		/**
		* SHeaderCtrl008::CreateChildren
		* @brief    ��������
		* @param    pugi::xml_node xmlNode  -- xml�����ļ�
		*
		* Describe  ��������
		*/
		virtual BOOL CreateChildren(pugi::xml_node xmlNode);

		bool IsLastItem(int iOrder);

		virtual void UpdateChildrenPosition()override;
		virtual CSize GetDesiredSize(LPCRECT pRcContainer);
			/**
			* SHeaderCtrl008::IsItemHover
			* @brief    �ж��Ƿ�Hover״̬
			* @param    DWORD dwHitTest
			* @return   ����BOOL
			*
			* Describe  �ж��Ƿ�Hover״̬
			*/
			BOOL IsItemHover(DWORD dwHitTest)
		{
			return dwHitTest != -1 && LOWORD(dwHitTest) == HIWORD(dwHitTest);
		}
// 			void StartAni();
// 			void StopAni();
		void OnDestroy();

		SOUI_MSG_MAP_BEGIN()
			MSG_WM_DESTROY(OnDestroy)
			SOUI_MSG_MAP_END()

		ISkinObj *    m_pSkinItem;  /**< ��ͷ����Skin */
		ISkinObj *    m_pSkinSort;  /**< �����־Skin */
		BOOL          m_bSortHeader;      /**< ��ͷ���Ե������ */
		BOOL          m_bFixWidth;        /**< �����ȹ̶����� */
		BOOL          m_bItemSwapEnable;  /**< �����϶�����λ�ÿ��� */

		BOOL            m_bDragging; /**< �����϶���־ */

		CPoint          m_ptClick;   /**< ��ǰ������� */
		DWORD           m_dwHitTest; /**< ���λ�� */
		DWORD           m_dwDragTo;  /**< �Ϸ�Ŀ�� */
		int             m_nAdjItemOldWidth;  /**< ���汻�϶����ԭʼ��� */
		SArray<SHeaderItem*> m_arrItems;
	};
}