/*
 * Module:   TRTC 关键类型定义
 * 
 * Function: 分辨率、质量等级等枚举和常量值的定义
 *
 */

#ifndef __TRTCCLOUDDEF_H__
#define __TRTCCLOUDDEF_H__

#include "TXLiteAVBase.h"
#include <memory>

#define WIN32_LEAN_AND_MEAN
#define _WINSOCKAPI_
#include <Windows.h>

/////////////////////////////////////////////////////////////////////////////////
/// \brief【视频分辨率 TRTCVideoResolution】
///
/// \desc 此处仅有横屏分辨率，如果要使用 360x640 这样的竖屏分辨率，需要指定 ResolutionMode 为 Portrait
///       [C]标记表示摄像头采集可以使用该分辨率
///       [S]标记表示屏幕采集可以使用该分辨率
/////////////////////////////////////////////////////////////////////////////////
enum TRTCVideoResolution
{
    /// 宽高比1:1
    TRTCVideoResolution_120_120   = 1,     /// [C] 建议码率 80kbps
    TRTCVideoResolution_160_160   = 3,     /// [C] 建议码率 100kbps
    TRTCVideoResolution_270_270   = 5,     /// [C] 建议码率 200kbps
    TRTCVideoResolution_480_480   = 7,     /// [C] 建议码率 350kbps
    
    /// 宽高比4:3
    TRTCVideoResolution_160_120   = 50,    /// [C] 建议码率 100kbps
    TRTCVideoResolution_240_180   = 52,    /// [C] 建议码率 150kbps
    TRTCVideoResolution_280_210   = 54,    /// [C] 建议码率 200kbps
    TRTCVideoResolution_320_240   = 56,    /// [C] 建议码率 250kbps
    TRTCVideoResolution_400_300   = 58,    /// [C] 建议码率 300kbps
    TRTCVideoResolution_480_360   = 60,    /// [C] 建议码率 400kbps
    TRTCVideoResolution_640_480   = 62,    /// [C] 建议码率 600kbps
    TRTCVideoResolution_960_720   = 64,    /// [C] 建议码率 1000kbps
    
    /// 宽高比16:9
    TRTCVideoResolution_160_90    = 100,   /// [C]
    TRTCVideoResolution_256_144   = 102,   /// [C]
    TRTCVideoResolution_320_180   = 104,   /// [C] 建议码率 250kbps
    TRTCVideoResolution_480_270   = 106,   /// [C] 建议码率 350kbps
    TRTCVideoResolution_640_360   = 108,   /// [C] 建议码率 550kbps
    TRTCVideoResolution_960_540   = 110,   /// [C] 建议码率 850kbps  
    TRTCVideoResolution_1280_720  = 112,   /// [C] 摄像头采集 - 建议码率 1200kbps  
	                                       /// [S] 屏幕分享   - 建议码率 低清：400kbps 高清：600kbps
    TRTCVideoResolution_1920_1080 = 114,   /// [S] 屏幕分享   - 建议码率 800kbps
};

/**
* 视频分辨率模式
*/
enum TRTCVideoResolutionMode
{
    TRTCVideoResolutionModeLandscape = 0,               ///< 横屏分辨率
    TRTCVideoResolutionModePortrait = 1,                ///< 竖屏分辨率
};

/**
* App场景类型
*/
enum TRTCAppScene
{
    TRTCAppSceneVideoCall = 0,                          ///< 视频通话场景，即绝大多数时间都是两人或两人以上视频通话的场景
                                                        ///  内部编码器和网络协议优化侧重流畅性，降低通话延迟和卡顿率
    
    TRTCAppSceneLIVE = 1,                               ///< 直播场景，即绝大多数时间都是一人直播，偶尔有多人视频互动的场景
                                                        ///  内部编码器和网络协议优化侧重性能和兼容性，性能和清晰度表现更佳
};

/**
* 视频流类型
*/
enum TRTCVideoStreamType
{
    TRTCVideoStreamTypeBig = 0,                         ///< 大画面视频流
    TRTCVideoStreamTypeSmall = 1,                       ///< 小画面视频流
    TRTCVideoStreamTypeSub = 2,                         ///< 辅流（屏幕分享）
};

/**
* 设备事件类型
*/
enum TRTCDeviceState
{
    TRTCDeviceStateAdd = 0,                             ///< 添加设备
    TRTCDeviceStateRemove = 1,                          ///< 移除设备
    TRTCDeviceStateActive = 2,                          ///< 设备已启用
};

/**
* 视频画面填充模式
*/
enum TRTCVideoFillMode
{
    TRTCVideoFillMode_Fill = 0,                         ///< 图像铺满屏幕，超出显示视窗的视频部分将被截掉
    TRTCVideoFillMode_Fit = 1,                          ///< 图像长边填满屏幕，短边区域会被填充黑色
};

/**
 * Qos流控模式，本地控制还是云端控制
 */
enum TRTCQosControlMode
{
    TRTCQosControlModeClient,                           ///< 客户端控制（用于SDK开发内部调试，客户请勿使用）
    TRTCQosControlModeServer,                           ///< 云端控制 （默认）
};

/**
 * 弱网下是“保清晰”还是“保流畅”
 * 弱网下保流畅 - 在遭遇弱网环境时，画面会变得模糊，且会有较多马赛克，但可以保持流畅不卡顿
 * 弱网下保清晰 - 在遭遇弱网环境时，画面会尽可能保持清晰，但可能会更容易出现卡顿
 */
enum TRTCVideoQosPreference
{
    TRTCVideoQosPreferenceSmooth = 1,                   ///< 弱网下保流畅
    TRTCVideoQosPreferenceClear = 2,                    ///< 弱网下保清晰
};

/**
* 美颜风格
*/
enum TRTCBeautyStyle
{
    TRTCBeautyStyleSmooth = 0,                         ///< 光滑
    TRTCBeautyStyleNature = 1,                         ///< 自然
};

/**
* 设备类型
*/
enum TRTCDeviceType
{
    TRTCDeviceTypeUnknow = -1,
    TRTCDeviceTypeMic = 0,                              ///< 麦克风
    TRTCDeviceTypeSpeaker = 1,                          ///< 扬声器
    TRTCDeviceTypeCamera = 2,                           ///< 摄像头
};

/**
* 视频数据结构类型
* 
* 该定义仅用于兼容原有接口，具体定义参见TXLiteAVBase.h文件
*/
typedef LiteAVVideoBufferType TRTCVideoBufferType;
#define TRTCVideoBufferType_Unknown LiteAVVideoBufferType_Unknown
#define TRTCVideoBufferType_Buffer LiteAVVideoBufferType_Buffer                 ///< 二进制Buffer类型
#define TRTCVideoBufferType_Texture LiteAVVideoBufferType_Texture               ///< 纹理类型

/**
* 视频帧的格式
* 
* 该定义仅用于兼容原有接口，具体定义参见TXLiteAVBase.h文件
*/
typedef LiteAVVideoPixelFormat TRTCVideoPixelFormat;
#define TRTCVideoPixelFormat_Unknown LiteAVVideoPixelFormat_Unknown
#define TRTCVideoPixelFormat_I420 LiteAVVideoPixelFormat_I420                   ///< I420
#define TRTCVideoPixelFormat_Texture_2D LiteAVVideoPixelFormat_Texture_2D       ///< OpenGL 2D 纹理
#define TRTCVideoPixelFormat_BGRA32 LiteAVVideoPixelFormat_BGRA32               ///< BGRA32

/**
* 音频帧的格式
* 
* 该定义仅用于兼容原有接口，具体定义参见TXLiteAVBase.h文件
*/
typedef LiteAVAudioFrameFormat TRTCAudioFrameFormat;
#define TRTCAudioFrameFormatNone LiteAVAudioFrameFormatNone
#define TRTCAudioFrameFormatPCM LiteAVAudioFrameFormatPCM                       ///< PCM

/**
 * 视频画面旋转方向
 * 
 * 该定义仅用于兼容原有接口，具体定义参见TXLiteAVBase.h文件
 */
typedef LiteAVVideoRotation TRTCVideoRotation;
#define TRTCVideoRotation0 LiteAVVideoRotation0                                 ///< 顺时针旋转0度
#define TRTCVideoRotation90 LiteAVVideoRotation90                               ///< 顺时针旋转90度
#define TRTCVideoRotation180 LiteAVVideoRotation180                             ///< 顺时针旋转180度
#define TRTCVideoRotation270 LiteAVVideoRotation270                             ///< 顺时针旋转270度

/**
* 水印图片的源类型
*/
enum TRTCWaterMarkSrcType
{
	TRTCWaterMarkSrcTypeFile = 0,                       ///< 图片文件路径，支持 BMP、GIF、JPEG、PNG、TIFF、Exif、WMF 和 EMF 文件格式
	TRTCWaterMarkSrcTypeBGRA32 = 1,                     ///< BGRA32格式内存块
	TRTCWaterMarkSrcTypeRGBA32 = 2,                     ///< RGBA32格式内存块
};

/**
* 日志类型
*/
enum TRTCLogLevel
{
    TRTCLogLevelNone = 0,                               ///< 不输出任何sdk log
    TRTCLogLevelVerbos = 1,                             ///< 输出所有级别的log
    TRTCLogLevelDebug = 2,                              ///< 输出 DEBUG，INFO，WARNING，ERROR 和 FATAL 级别的log
    TRTCLogLevelInfo = 3,                               ///< 输出 INFO，WARNNING，ERROR 和 FATAL 级别的log
    TRTCLogLevelWarn = 4,                               ///< 只输出WARNNING，ERROR 和 FATAL 级别的log
    TRTCLogLevelError = 5,                              ///< 只输出ERROR 和 FATAL 级别的log
    TRTCLogLevelFatal = 6,                              ///< 只输出 FATAL 级别的log
};

/////////////////////////////////////////////////////////////////////////////////
/// \brief【进房参数 TRTCParams】
///
/// \desc 作为 TRTC SDK 的进房参数，只有该参数填写正确，才能顺利进入 roomid 指定的房间
/////////////////////////////////////////////////////////////////////////////////
struct TRTCParams
{
    /// 应用标识 - [必填] - 腾讯视频云基于 sdkAppId 完成计费统计
    uint32_t sdkAppId;
	
    /// 房间号码 [必填] 指定房间号，在同一个房间里的用户（userId）可以彼此看到对方并进行视频通话
    uint32_t roomId;
	
    /// 用户标识 - [必填] - 当前用户的 userid，相当于用户名,UTF-8编码
    const char* userId;
	
    /// 用户签名 - [必填] - 当前 userId 对应的验证签名，相当于登录密码
    const char* userSig;
	
    /// 房间签名 - [非必选] - 如果您希望某个房间（roomId）只让特定的某些用户（userId）才能进入，就需要使用 privateMapKey 进行权限保护
    const char* privateMapKey;
    /// 业务数据 - [非必选] - 某些非常用的高级特性才需要用到此字段
    const char* businessInfo;

    TRTCParams()
        : sdkAppId(0)
        , roomId(0)
        , userId(NULL)
        , userSig(NULL)
        , privateMapKey(NULL)
        , businessInfo(NULL)
    {

    }
};

/////////////////////////////////////////////////////////////////////////////////
/// \brief【编码参数 TRTCVideoEncParam】
///
/// \desc 视频编码器相关参数，该设置决定了远端用户看到的画面质量（同时也是云端录制出的视频文件的画面质量）
/////////////////////////////////////////////////////////////////////////////////
struct TRTCVideoEncParam
{
    /// 视频分辨率
    ///
    /// \note 您在 TRTCVideoResolution 只能找到横屏模式的分辨率，比如： 640x360 这样的分辨率
    ///       如果想要使用竖屏分辨率，请指定 resMode 为 Portrait，比如：640x360 + Portrait = 360x640
    /// \note 屏幕分享不支持竖屏分辨率
    TRTCVideoResolution videoResolution;
	
    /// 分辨率模式（横屏分辨率 - 竖屏分辨率）
    ///
    /// \note 如果 videoResolution 指定分辨率 640x360，resMode 指定模式为 Portrait，则最终编码出的分辨率为 360x640
    TRTCVideoResolutionMode resMode;

	/// 视频采集帧率
    /// 摄像头采集时推荐设置为 15fps 或 20fps，10fps以下会有明显的卡顿感，20fps以上则没有必要
    /// 屏幕采集时推荐设置为10fps 或 15fps
    ///
    /// \note 很多廉价的 USB 摄像头可能并不支持 15fps 以上的采集帧率
    ///
    uint32_t videoFps;

    /// 视频上行码率
    ///
    /// \note 推荐设置请参考 TRTCVideoResolution 定义处的注释说明
    uint32_t videoBitrate;

    TRTCVideoEncParam()
        : videoResolution(TRTCVideoResolution_640_360)
        , resMode(TRTCVideoResolutionModeLandscape)
        , videoFps(15)
        , videoBitrate(550)
    {

    }
};

/////////////////////////////////////////////////////////////////////////////////
/// \brief【网络流控相关参数 TRTCNetworkQosParam】
///
/// \desc 网络流控相关参数，该设置决定了SDK在各种网络环境下的调控方向（比如弱网下是“保清晰”还是“保流畅”）
/////////////////////////////////////////////////////////////////////////////////
struct TRTCNetworkQosParam
{
    /// 弱网下是“保清晰”还是“保流畅”
    ///
    /// 弱网下保流畅 - 在遭遇弱网环境时，画面会变得模糊，且会有较多马赛克，但可以保持流畅不卡顿
    /// 弱网下保清晰 - 在遭遇弱网环境时，画面会尽可能保持清晰，但可能会更容易出现卡顿
    TRTCVideoQosPreference preference;

    /// 视频分辨率（云端控制 - 客户端控制）
    ///
    /// Client 模式：客户端控制模式，用于SDK开发内部调试，客户请勿使用
    /// Server 模式（默认）：云端控制模式，若没有特殊原因，请直接使用该模式
    TRTCQosControlMode controlMode;
	
    TRTCNetworkQosParam()
        : preference(TRTCVideoQosPreferenceClear)
        , controlMode(TRTCQosControlModeServer)
    {

    }
};

/////////////////////////////////////////////////////////////////////////////////
/// \brief【音量大小 TRTCVolumeInfo】
///
/// \desc 表示语音音量的评估大小，通过这个数值，您可以在 UI 界面上用图标表征 userId 是否有在说话 
/////////////////////////////////////////////////////////////////////////////////
struct TRTCVolumeInfo
{
    const char* userId;                           ///< 说话者的userId,字符编码格式是UTF-8,
    uint32_t volume;                        ///< 说话者的音量, 取值范围 0~100

    TRTCVolumeInfo()
        : userId(NULL)
        , volume(0)
    {

    }
};

/////////////////////////////////////////////////////////////////////////////////
/// \brief【质量评分 TRTCQualityInfo】
///
/// \desc 质量评分，通过这个数值，您可以在 UI 界面上用图标表征 userId 的通话线路质量 
/////////////////////////////////////////////////////////////////////////////////
enum TRTCQuality
{
    TRTCQuality_Unknown = 0,
    TRTCQuality_Excellent = 1,
    TRTCQuality_Good = 2,
    TRTCQuality_Poor = 3,
    TRTCQuality_Bad = 4,
    TRTCQuality_Vbad = 5,
    TRTCQuality_Down          = 6, 
};

struct TRTCQualityInfo
{
    const char* userId;                        ///< 用户标识
    TRTCQuality quality;                    ///< 视频质量

    TRTCQualityInfo()
        : userId(NULL)
        , quality(TRTCQuality_Unknown)
    {

    }
};

/**
* 视频帧数据
* 
* 该定义仅用于兼容原有接口，具体定义参见TXLiteAVBase.h文件
*/
typedef LiteAVVideoFrame TRTCVideoFrame;

/**
* 音频帧数据
* 
* 该定义仅用于兼容原有接口，具体定义参见TXLiteAVBase.h文件
*/
typedef LiteAVAudioFrame TRTCAudioFrame;


/////////////////////////////////////////////////////////////////////////////////
/// \brief【网络测速结果 TRTCSpeedTestResult】
///
/// \desc 您可以在用户进入房间前通过 TRTCCloud 的 startSpeedTest 接口进行测速 （注意：请不要在通话中调用）
///       测速结果会每 2~3 秒钟返回一次，每次返回一个 ip 地址的测试结果，其中：
///
///  >> quality 是内部通过评估算法测算出的网络质量，loss 越低，rtt 越小，得分也就越高
///  >> upLostRate 是指上行丢包率，例如 0.3 代表每向服务器发送10个数据包，可能有3个会在中途丢失
///  >> downLostRate 是指下行丢包率，例如 0.2 代表从服务器每收取10个数据包，可能有2个会在中途丢失
///  >> rtt 是指当前设备到腾讯云服务器的一次网络往返时间，正常数值在 10ms ~ 100ms 之间
/////////////////////////////////////////////////////////////////////////////////

struct TRTCSpeedTestResult
{
    /// 服务器ip地址
    const char* ip;

    /// 网络质量
    ///
    /// 内部通过评估算法测算出的网络质量，loss 越低，rtt 越小，得分也就越高
    TRTCQuality quality;

    /// 上行丢包率，范围是[0,1.0]
    ///
    /// 例如 0.3 代表每向服务器发送10个数据包，可能有3个会在中途丢失
    float upLostRate;

    /// 下行丢包率，范围是[0,1.0]
    ///
    /// 例如 0.2 代表从服务器每收取10个数据包，可能有2个会在中途丢失
    float downLostRate;

    /// 延迟（毫秒）：代表 SDK 跟服务器一来一回之间所消耗的时间，这个值越小越好
    ///
    /// 是指当前设备到腾讯云服务器的一次网络往返时间，正常数值在 10ms ~ 100ms 之间
    int rtt;

    TRTCSpeedTestResult()
        : ip(NULL)
        , upLostRate(0.0f)
        , downLostRate(0.0f)
        , rtt(0)
    {

    }
};

/////////////////////////////////////////////////////////////////////////////////
/// \brief【旁路推流参数 TRTCPublishCDNParam】
///
/// \desc 旁路转推
/////////////////////////////////////////////////////////////////////////////////
struct TRTCPublishCDNParam
{
    /// 腾讯云 AppID，在直播控制台-直播码接入可查询到
    uint32_t appId;

    /// 腾讯云直播bizid，在直播控制台-直播码接入可查询到
    uint32_t bizId;

    /// 旁路转推的URL
    const char* url;

    TRTCPublishCDNParam()
        : url(NULL)
        , appId(0)
        , bizId(0)
    {

    }
};

/////////////////////////////////////////////////////////////////////////////////
/// \brief【转码混流设置 TRTCTranscodingConfig】
///
/// \desc 设置旁路流的转码混流格式
/////////////////////////////////////////////////////////////////////////////////
struct TRTCMixUser
{
    /// 参与混流的userId
    const char* userId;

    /// 图层位置坐标以及大小，左上角为坐标原点(0,0) （绝对像素值）
    RECT rect;

    /// 图层层次 （1-15） 不可重复
    int zOrder;

	/// 参与混合的是主路画面(TRTCVideoStreamTypeBig)还是屏幕分享(TRTCVideoStreamTypeSub)画面
    TRTCVideoStreamType streamType;

    TRTCMixUser()
        : userId("")
        , rect()
        , zOrder(0)
        , streamType(TRTCVideoStreamTypeBig)
    {
        rect.left = 0;
        rect.top = 0;
        rect.right = 0;
        rect.bottom = 0;
    }
};

enum TRTCTranscodingConfigMode {

    TRTCTranscodingConfigMode_Unknown = 0,

    /// 手动配置混流config信息
    TRTCTranscodingConfigMode_Manual = 1,
};

struct TRTCTranscodingConfig
{
    /// 转码config模式 @see TRTCTranscodingConfigMode
    TRTCTranscodingConfigMode mode;

    /// 腾讯云 AppID，在直播控制台-直播码接入可查询到
    uint32_t appId;

    /// 腾讯云直播bizid，在直播控制台-直播码接入可查询到
    uint32_t bizId;

    /// 视频分辨率：宽
    uint32_t videoWidth;

    /// 视频分辨率：高
    uint32_t videoHeight;

    /// 视频码率
    uint32_t videoBitrate;

    /// 视频帧率
    uint32_t videoFramerate;

    /// 视频GOP，单位秒
    uint32_t videoGOP;

    /// 音频采样率 48000
    uint32_t audioSampleRate;

    /// 音频码率   64K
    uint32_t audioBitrate;

    /// 声道数     2
    uint32_t audioChannels;

    /// 混流用户配置列表
    TRTCMixUser* mixUsersArray;

    /// 数组mixUsersArray的大小
    uint32_t mixUsersArraySize;

    TRTCTranscodingConfig()
        : mode(TRTCTranscodingConfigMode_Unknown)
        , videoWidth(-1)
        , videoHeight(-1)
        , videoBitrate(-1)
        , videoFramerate(-1)
        , videoGOP(-1)
        , audioSampleRate(-1)
        , audioBitrate(-1)
        , audioChannels(-1)
        , mixUsersArray(nullptr)
        , mixUsersArraySize(0)
    {}
};

/////////////////////////////////////////////////////////////////////////////////
/// \brief【屏幕分享窗口信息 TRTCScreenCaptureSourceInfo】
///
/// \desc 您可以通过 getScreenCaptureSources() 枚举可共享的窗口列表，列表通过 ITRTCScreenCaptureSourceList 返回
/////////////////////////////////////////////////////////////////////////////////

typedef LiteAVScreenCaptureSourceType TRTCScreenCaptureSourceType;
#define TRTCScreenCaptureSourceTypeUnknown LiteAVScreenCaptureSourceTypeUnknown
#define TRTCScreenCaptureSourceTypeWindow  LiteAVScreenCaptureSourceTypeWindow                 ///< 二进制Buffer类型
#define TRTCScreenCaptureSourceTypeScreen  LiteAVScreenCaptureSourceTypeScreen               ///< 纹理类型
#define TRTCScreenCaptureSourceTypeCustom  LiteAVScreenCaptureSourceTypeCustom               ///< 纹理类型

typedef LiteAVImageBuffer TRTCImageBuffer;
typedef LiteAVScreenCaptureSourceInfo TRTCScreenCaptureSourceInfo;
typedef ILiteAVScreenCaptureSourceList ITRTCScreenCaptureSourceList;

/////////////////////////////////////////////////////////////////////////////////
/// \brief【获取SDK设备信息接口 ITRTCDeviceCollection】
///
/// \desc 您可以通过 getMicDevicesList()/getSpeakerDevicesList()/getMicDevicesList 枚举硬件设备列表，列表通过 ITRTCDeviceCollection 返回
/////////////////////////////////////////////////////////////////////////////////
typedef ILiteAVDeviceCollection ITRTCDeviceCollection;

#endif /* __TRTCCLOUDDEF_H__ */