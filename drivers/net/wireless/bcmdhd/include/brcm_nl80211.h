/*
 * Definitions for nl80211 vendor command/event access to host driver
 *
 * $ Copyright Open Broadcom Corporation $
 *
 *
 * <<Broadcom-WL-IPTag/Open:>>
 *
 * $Id: brcm_nl80211.h 556083 2015-05-12 14:03:00Z $
 *
 */

#ifndef _brcm_nl80211_h_
#define _brcm_nl80211_h_

#define OUI_BRCM  0x001018

enum wl_vendor_subcmd {
	BRCM_VENDOR_SCMD_UNSPEC,
	BRCM_VENDOR_SCMD_PRIV_STR,
	BRCM_VENDOR_SCMD_BCM_STR
};


struct bcm_nlmsg_hdr {
	uint cmd;	/* common ioctl definition */
	int len;	/* expected return buffer length */
	uint offset;	/* user buffer offset */
	uint set;	/* get or set request optional */
	uint magic;	/* magic number for verification */
};

enum bcmnl_attrs {
	BCM_NLATTR_UNSPEC,

	BCM_NLATTR_LEN,
	BCM_NLATTR_DATA,

	__BCM_NLATTR_AFTER_LAST,
	BCM_NLATTR_MAX = __BCM_NLATTR_AFTER_LAST - 1
};

struct nl_prv_data {
	int err;			/* return result */
	void *data;			/* ioctl return buffer pointer */
	uint len;			/* ioctl return buffer length */
	struct bcm_nlmsg_hdr *nlioc;	/* bcm_nlmsg_hdr header pointer */
};

#endif /* _brcm_nl80211_h_ */
