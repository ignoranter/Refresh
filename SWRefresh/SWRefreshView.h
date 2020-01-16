//
//  SWRefreshView.h
//  SWRefresh
//
//  Created by Li Xiangming on 18/12/31.
//  Copyright © 2015年 SWRefresh All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SWRefreshViewModel.h"

@protocol SWRefreshView

@required
@property (nonatomic, strong, nullable) SWRefreshViewModel* sourceViewModel;

@optional
/** return default headerViewModelClass. used when need to create one. */
+ (_Nonnull Class)defaultHeaderViewModelClass;
/** return default footerViewModelClass. used when need to create one. */
+ (_Nonnull Class)defaultFooterViewModelClass;

/** return default id<SWRefreshHeaderController> class. used when need to create one. */
+ (_Nonnull Class)defaultHeaderControllerClass;
/** return default id<SWRefreshFooterController> class. used when need to create one. */
+ (_Nonnull Class)defaultFooterControllerClass;

@end


@protocol SWRefreshHeaderController, SWRefreshFooterController;

// Class Of Refresh View
@interface SWRefreshView : UIView <SWRefreshView> 

/** one shot for create controller, view and ViewModel and bind them */
+ (id<SWRefreshHeaderController>_Nullable)headerWithRefreshingBlock:(SWRefreshingBlock _Nonnull )block;
+ (id<SWRefreshHeaderController>_Nullable)headerWithRefreshingTarget:(id _Nonnull )target action:(SEL _Nonnull )action;

+ (id<SWRefreshFooterController>_Nullable)footerWithRefreshingBlock:(SWRefreshingBlock _Nonnull )block;
+ (id<SWRefreshFooterController>_Nullable)footerWithRefreshingTarget:(id _Nonnull )target action:(SEL _Nonnull)action;

/** one shot for create a view and respond ViewModel */
+ (instancetype _Nullable)newHeaderRefreshingBlock:(SWRefreshingBlock _Nonnull)block;
+ (instancetype _Nullable)newHeaderRefreshingTarget:(id _Nonnull)target action:(SEL _Nonnull)action;

+ (instancetype _Nullable)newFooterRefreshingBlock:(SWRefreshingBlock _Nonnull)block;
+ (instancetype _Nullable)newFooterRefreshingTarget:(id _Nonnull)target action:(SEL _Nonnull)action;

#pragma mark   Overridable Method
- (void)changePullingPercent:(CGFloat)pullingPercent;
- (void)changeFromState:(SWRefreshState)oldState to:(SWRefreshState)newState;

- (void)bindSourceViewModel:(SWRefreshViewModel* _Nullable)sourceViewModel NS_REQUIRES_SUPER;
- (void)unbindSourceViewModel:(SWRefreshViewModel* _Nullable)sourceViewModel NS_REQUIRES_SUPER;

@end
