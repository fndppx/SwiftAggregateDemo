//
//  Comment.h
//  Vhallphone
//
//  Created by vhall on 13-12-28.
//  Copyright (c) 2013年 vhall. All rights reserved.
//

#ifndef VhallIphone_Comment_h
#define VhallIphone_Comment_h

#ifdef DEBUG // 调试状态, 打开LOG功能
#define NSLog(...) NSLog(__VA_ARGS__)
#else // 发布状态, 关闭LOG功能
#define NSLog(...)
#endif

#ifdef DEBUG // 调试状态, 打开LOG功能
#define VHLog(...) NSLog(__VA_ARGS__)
#else // 发布状态, 关闭LOG功能
#define VHLog(...)
#endif


//块引用
#define WeakObj(o) autoreleasepool{} __weak typeof(o) o##Weak = o;
#define StrongObj(o) autoreleasepool{} __strong typeof(o) o = o##Weak;


//#ifdef DEBUG // 调试状态, 打开   LOG功能
//#define VHERRORLog(...) NSLog(__VA_ARGS__)
//#else // 发布状态, 关闭LOG功能
//#define VHERRORLog(...)
//#endif
#define VHERRORLog(...)

#define VH_UPADTEURL @"http://itunes.apple.com/CN/app/id840884836"

/////////////////////////////////////////////////////////////账号
//信鸽
#define XGAppId         2200035304
#define XGAppKey        @"I16V25T4WMQS"
//友盟
#define UMAPPKEY        @"53b20c6b56240ba6080820ba"
//ShareSDK
#define ShareSDKAppId   @"11c9d4bdd658"
//微信 需支付权限
#define WXAppId         @"wxe318f9021d5df149"
#define WXAppSecret     @"cdd31720cc4e37cec6935367f58507d8"
//微博
#define WBAppKey        @"2075019406"
#define WBAppSecret     @"a4346112b4166b112fe4edf4a74cab88"
#define WBRedirectUri   @"http://www.vhall.com/app/index.html"
//QQ
#define QQAppId         @"101031821"
#define QQAppKey        @"bf9b8b18abee496b18f58d94a9c53539"
//支付宝
#define AliPayAppScheme @"vhalliphone"
//OneAPM
#define OneAPMToken     @"9520E10793BE39B3163FA473A6E6D41933"
//环信
#define Hyphenate       @"vhall#vhallapp"

/////////////////////////////////////////////////////////////
//HOME页
#define VHHOME_elementArr       @[@"关注",@"推荐"]
#define VHHOME_elementNetArr    @[VHNET_webinar_interest,VHNET_webinar_recommend]
#define VHHOME_CacheArr         @[@"KHomeCache0",@"KHomeCache1"]//首页数据缓存
#define VHHOME_CacheTimeout     3600*24
/////////////////////////////////////////////////////////////

//关注页
#define VHFOCUS_elementNetArr   @[VHNET_user_hate,VHNET_user_focus]
//发现页
#define VHFIND_elementNetArr   @[VHNET_webinar_hots,VHNET_webinar_recommend,VHNET_webinar_preview]
#define VHFIND_titleArr        @[@"热门",@"推荐",@"预告"]
#define VHFIND_CacheArr        @[@"hot",@"recommend",@"predict"]

//消息标题
#define VHMESSAGE_notifiTitleArr     @[@"通知",@"回复",@"私信"]

//用户信息
#define KCacheTimeoutInterval   86400*30*12*30
#define KCacheUserItem          @"KuserItem"
#define KCacheThirdPartyUser    @"ThirdPartyuser"
/////////////////////////////////////////////////////////////
//启动信息
#define VHLaunchItem_Cache      @"KLaunchItem"
#define VHLaunchItem_Clicked    @"KLaunchItemClicked"//点击广告
#define VHLaunchItem_Timeout    86400*30*12*30

//系统更新
#define  VHSystemVersionInfo     @"systemVersionInfo"

//系统跟新信息缓存时间
#define VHSystemUpateCacheTimeout     3600

#define TOOLBAR_HEIGHT 35.0
#define SAFE_RELEASE(obj) if(obj){[obj release];obj=nil;}

//获取物理屏幕的尺寸
#define VHScreenHeight  ([UIScreen mainScreen].bounds.size.height)
#define VHScreenWidth   ([UIScreen mainScreen].bounds.size.width)
#define VH_SW           ((VHScreenWidth<VHScreenHeight)?VHScreenWidth:VHScreenHeight)
#define VH_SH           ((VHScreenWidth<VHScreenHeight)?VHScreenHeight:VHScreenWidth)
#define VH_RATE         (VH_SW/320.0)
#define VH_RATE_SCALE   (VH_SW/375.0)//以ip6为标准 ip5缩小 ip6p放大 zoom
#define VH_RATE_6P      ((VH_SW>375.0)?VH_SW/375.0:1.0)//只有6p会放大


#define VH_Device_OS_ver [[UIDevice currentDevice] systemVersion]
#define VH_APP_ver       [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define VH_APP_Build_ver [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]


#define VH_SID    ([VHTools emptyForNil:[VHUserServer sid]])
#define VH_icon   ([VHTools emptyForNil:[VHUserServer currentUser].icon])
#define VH_userId ([VHTools emptyForNil:[VHUserServer currentUser].userId])
#define VH_name   ([VHTools emptyForNil:[VHUserServer currentUser].nickName])
#define VH_Phone  ([VHTools emptyForNil:[VHUserServer currentUser].phone])


#define VH_UserDefaults [NSUserDefaults standardUserDefaults]
#define VH_SETTING      [VHStystemSetting sharedSetting]
#define VH_THEME        [VHThemeManager sharedManager]




#define VHNNKEY_LiveNowOrReserve    @"VHLiveNowOrReserveViewController"
#define VHNNKEY_LIVE_BUY_SUCCESS    @"VIDEOBUYSUCCESS"
#define VHNNKEY_LIVE_SHARE          @"VIDEOSHAREMODELINFO"
#define VHNNKEY_CLOSE_SEARCH        @"CLOSESEARCH"
#define VHNNKEY_GOSEARCHCONTENT     @"gotoSearchConent"
#define VHNNKEY_RefreshData         @"refreshData"
#define VHNNKEY_Login_Out           @"LoginOut"
#define VHNNKEY_ReferNetStatus      @"refreshNetStatus"//更新网络数据
#define VHNNKEY_clearUserData       @"clearUserData" //重复账号登陆 退出登陆
#define VHNNKEY_countUnreadMessage  @"unreadMessage" //统计未读消息数
#define VHNNKEY_FOCUS_SCROLLTOTOP   @"fousscrollToTop"   //关注页滑到顶部
#define VHNNKEY_FIND_SCROLLTOTOP    @"findscrollToTop"   //发现滑到顶部
#define VHNNKEY_MESSAGE_CHANGEVC    @"messageChangeVC"   //点击消息 切换对应页面
#define VHNNKEY_MESSAGE_reduceTagCount  @"reduceTagCount" //统计回复标签数
#define VHHOME_PAGE_CNT @"30" //一页多少条
#define VHRANK_PAGE_CNT @"15" //一页多少条
#define VHUSER_PAGE_CNT @"16" //一页多少条
#define VHComment_PAGE_CNT @"20"  //一页多少条
#define VHInvite_PAGE_CNT @"30"  //一页多少条


#define VHHOME_ITEM_HEIGHT  (VHScreenWidth*9/16)
#define VH_SHARE_STR    @"http://vhall.com"
#define VH_SHARE_IMAGE  @"icon_vhall"
#define kNETWORKUNAVAILABLE      @"当前没有网络,请检查网络设置"

#define kIsFirstLaunchApp            @"firstLaunchApp"
#define kNoUserInfoLogIn             @"noUserInfoLogin"
//#define kSaveThirdsLogInUidAndType   @"saveThirdsLoginUidAndType"

//和设置相关的标记
#define kWIFI               @"isWifi"
#define kNOTIFY             @"isNotify"
#define kISLOGIN            @"islogin"
#define KPUSH               @"livepushuser"

//发起端视频质量 0用来区分默认值
#define kVideoResolution1 1//640*480 分辨率
#define kVideoResolution2 2//960*540
#define kVideoResolution3 3//1280*720
#define KBitRate100 100
#define KBitRate300 300
#define KBitRate500 500
#define KBitRate700 700
#define kBitRate @"BitRate"

//未倒入通讯录两周后提醒
#define kNumberOfDaysShowAgain   14
#define kTimeFlag                @"timeFlag"
#define kTime                    @"time"

#define VH_CurViewY(view)       (int)(view.frame.origin.y+view.frame.size.height)
#define VH_CurViewYS(view,step) (int)(view.frame.origin.y+view.frame.size.height+(step))
//请求失败提示
#define VH_NET_CODE_ERROR(a) {\
if(a)\
[self showTextView:self.view message:a.msg];\
else\
[self showTextView:self.view message:@"网络超时请重试！"];\
}

#define VH_NET_CODE_ERROR_WEAKSELF(a,b) {\
if((b))\
[(a) showTextView:(a).view message:(b).msg];\
else\
[(a) showTextView:(a).view message:@"网络超时请重试！"];\
}
//不存在用户登录信息 userdefaults
#define VH_NO_USER_INFO_LOGIN(a){\
[[NSUserDefaults standardUserDefaults] setObject:a forKey:kNoUserInfoLogIn];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}

//第三方登陆保存open_id 和登陆类型
//#define VH_SAVE_THIRDSLOGIN_INFO(b){\
//[[NSUserDefaults standardUserDefaults] setObject:b forKey:kSaveThirdsLogInUidAndType];\
//[[NSUserDefaults standardUserDefaults] synchronize];\
//}


//状态栏异常tabbar处理 
#define VH_DEALWITH_STATUSBARCHANGE_TABBARRESET(c){\
[[NSNotificationCenter defaultCenter] postNotificationName:UIApplicationWillChangeStatusBarFrameNotification object:nil userInfo:@{@"tabbarInfo":c}];\
}

//nil串置@""
#define EmptyForNil(a) [VHTools emptyForNil:a]
//颜色
#define MakeColor(r,g,b,a) ([UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a])
#define MakeColorRGB(hex)  ([UIColor colorWithRed:((hex>>16)&0xff)/255.0 green:((hex>>8)&0xff)/255.0 blue:(hex&0xff)/255.0 alpha:1.0])
#define MakeColorRGBA(hex,a) ([UIColor colorWithRed:((hex>>16)&0xff)/255.0 green:((hex>>8)&0xff)/255.0 blue:(hex&0xff)/255.0 alpha:a])
#define MakeColorARGB(hex) ([UIColor colorWithRed:((hex>>16)&0xff)/255.0 green:((hex>>8)&0xff)/255.0 blue:(hex&0xff)/255.0 alpha:((hex>>24)&0xff)/255.0])


#define BackgroundColor MakeColorRGB(0xe2e8eb)
#define NavColor        MakeColor(25, 24, 29, 1)
#define CellColor       MakeColor(25, 24, 29, 1)
#define VideoBgColor    MakeColor(18, 18, 18, 1)
//关注
#define FollowBtnColor       MakeColorRGB(0xff3333)
#define FollowBtnDownColor   MakeColorRGB(0x5096ff)

//排行榜关注按钮颜色
#define FollowBtnTop5       MakeColorRGB(0x222222)
#define ViewLineColor        MakeColor(49,49,54,1.0)//(220,220,220,1.0)
//按钮颜色
#define SendBtnColor    MakeColorRGB(0xffffff)

//分割线的颜色

#define blueIphoneColor MakeColorRGB(0xef5738)

//Btn灰红色
#define ButtonTintRedColor MakeColorRGB(0xde2c2c)
//Btn蓝灰色
#define ButtonTintBlueColor MakeColorRGB(0x4682de)
//Btn浅灰
#define ButtonTintGrayColor MakeColorRGB(0xb2b2b4)

#define TextBlueColor   MakeColor(0,123,198,1.0)
#define subTitleColor   MakeColor(153,153,153,1.0)
#define navBarColor     MakeColor(27,37,46,1.0)

//浅灰
#define colorlightGray  MakeColor(153,153,153,1.0)
#define colorDarkGray   MakeColor(69,69,69,1.0)
#define colorBlue       MakeColor(0,123,198,1.0)
//新版本的颜色
#define KBLACKTEXTCOLOR MakeColor(37,37,37,1.0)
#define KGRAYTEXTCOLOR  MakeColor(175,175,175,1.0)
#define KREDEXTCOLOR    MakeColor(209,7,20,1.0)

#ifdef UI_USER_INTERFACE_IDIOM
#define IS_IPAD() (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#else
#define IS_IPAD() (false)
#endif

#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

//放大版的iphone6等于Iphone5的分辨率《求区别办法》
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)) : NO)

#define iPhone6plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)) : NO)

#define iPhone5_frame CGRectMake(0, 0, 320, 548 - 44)
#define iPhone4_frame CGRectMake(0, 0, 320, 460 - 44)
#define ios7 ([[UIDevice currentDevice].systemVersion doubleValue] <8 ? YES : NO )


#define IS_WIDESCREEN_5                            (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)568) < __DBL_EPSILON__)
#define IS_WIDESCREEN_6                            (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)667) < __DBL_EPSILON__)
#define IS_WIDESCREEN_6Plus                        (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)736) < __DBL_EPSILON__)
#define IS_IPHONE                                  ([[[UIDevice currentDevice] model] isEqualToString: @"iPhone"] || [[[UIDevice currentDevice] model] isEqualToString: @"iPhone Simulator"])
#define IS_IPOD                                    ([[[UIDevice currentDevice] model] isEqualToString: @"iPod touch"])
#define IS_IPHONE_5                                (IS_IPHONE && IS_WIDESCREEN_5)
#define IS_IPHONE_6                                (IS_IPHONE && IS_WIDESCREEN_6)
#define IS_IPHONE_6Plus                            (IS_IPHONE && IS_WIDESCREEN_6Plus)





//直播通知



#define LIVEACTIVATTESUCCESS            @"liveActivateSuccessNotification"
#define LIVECONTENTFIELD                @"liveConnectionFieldNotification"
#define LIVEFILESIZENOTIFICATION        @"uploadFileSizeNotification"
#define LIVEFILESIZEKEY                 @"filesize"
#define LIVEFIRSTCAPTUREIMAGE           @"liveFirstCaptureImage"
#define USERACTIVITYLISTREFRESH         @"userActivityListRefreshNotification"//用户直播列表刷新
#define USERINCOMEREFRESH               @"userIncomeRefreshNotification"//用户收益刷新
#define LIVEENDRETURNHOMEVIEW           @"returnHomeViewAfterLIveEnd"  //直播结束后返回首页

#define NOUSERINFOLOGINSUCCESS          @"noExistUserLoginSuccess" //不存在用户信息登录成功
#define ADDRESSBOOKALERTVIEW            @"addressBookAlertView"   //通讯录弹窗

#define WEIBOAUTHORRESPONSE             @"weiboAuthorResponse"   //获取微博好友授权回调

#endif //#define VhallIphone_Comment_h
