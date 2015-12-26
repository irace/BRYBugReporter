//  BugshotKit.h
//  See included LICENSE file for the (MIT) license.
//  Created by Marco Arment on 1/15/14.

#import <UIKit/UIKit.h>
#import "BSKMainViewController.h"
#import "BSKWindow.h"

#if ! DEBUG
#warning BugshotKit is being included in a non-debug build.
#endif

@protocol BugshotKitDelegate

- (BOOL)bugshotKitShouldPresent;

- (void)bugshotKitDidSubmit:(nonnull BSKSubmission *)submission;

@end

NS_ASSUME_NONNULL_BEGIN

extern NSString * const BSKNewLogMessageNotification;

typedef enum : NSUInteger {
    BSKInvocationGestureNone        = 0,
    BSKInvocationGestureSwipeUp     = 1,
    BSKInvocationGestureSwipeDown   = (1 << 1),
    BSKInvocationGestureSwipeFromRightEdge = (1 << 2), // For whatever reason, this gesture recognizer always only needs one touch, regardless of your numberOfTouches setting.
    BSKInvocationGestureDoubleTap = (1 << 3),
    BSKInvocationGestureTripleTap = (1 << 4),
	BSKInvocationGestureLongPress = (1 << 5),
    BSKInvocationGesture_VolumeButton_DoubleTap = (1 << 6),
} BSKInvocationGestureMask;

@interface BugshotKit : NSObject <UIGestureRecognizerDelegate, BSKMainViewControllerDelegate>

/*
    Call this from your UIApplication didFinishLaunching:... method.
*/
+ (void)enableWithNumberOfTouches:(NSUInteger)fingerCount performingGestures:(BSKInvocationGestureMask)invocationGestures;

/* You can also always show it manually */
+ (void)show;
+ (void)dismissAninmated:(BOOL)animated completion:(nullable void(^)())completion;

+ (instancetype)sharedManager;
- (void)clearLog;

+ (void)addLogMessage:(NSString *)message;
+ (UIFont *)consoleFontWithSize:(CGFloat)size;

@property (nonatomic) NSUInteger consoleLogMaxLines;

/*
 You can display the console log viewer as selectable text. Defaults to NO which presents a screenshot of the log text.

 @param displayText YES if the console log should be displayed as selectable text. NO if it should use a screenshot.
 */
+ (void)setDisplayConsoleTextInLogViewer:(BOOL)displayText;

// feel free to mess with these if you want

- (void)currentConsoleLogWithDateStamps:(BOOL)dateStamps
                         withCompletion:(void (^)(NSString *result))completion;

- (void)consoleImageWithSize:(CGSize)size
                    fontSize:(CGFloat)fontSize
             emptyBottomLine:(BOOL)emptyBottomLine
              withCompletion:(void (^)(UIImage *result))completion;

@property (nonatomic, weak) id<BugshotKitDelegate> delegate;

@property (nonatomic) BOOL displayConsoleTextInLogViewer;
@property (nonatomic, strong) UIColor *annotationFillColor;
@property (nonatomic, strong) UIColor *annotationStrokeColor;
@property (nonatomic, strong) UIColor *toggleOnColor;
@property (nonatomic, strong) UIColor *toggleOffColor;


// don't mess with these
@property (nonatomic, strong, nullable) UIImage *snapshotImage;
@property (nonatomic, copy, nullable) NSArray *annotations;
@property (nonatomic, strong, nullable) UIImage *annotatedImage;

#pragma mark - Volume Button Options

/**
 Defaults to NO.
 */
@property (assign, nonatomic) BOOL allowBugshotVolumeTapTriggerWhenAudioIsPlaying;

/**
 Defaults to NO.
 */
@property (assign, nonatomic) BOOL allowBugshotVolumeTapTriggerWhenVideoIsPlaying;

@end

UIImage *BSKImageWithDrawing(CGSize size, void (^drawingCommands)());

NS_ASSUME_NONNULL_END
