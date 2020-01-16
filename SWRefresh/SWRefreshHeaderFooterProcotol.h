//
//  SWRefreshHeaderFooterProcotol.h
//  Refresh
//
//  Created by Li Xiangming on 2019/1/16.
//  Copyright © 2020 Li Xiangming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SWRefreshView.h"
#import "SWRefreshHeaderViewModel.h"
#import "SWRefreshFooterViewModel.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Header Protocol

/** 该协议用于控制要使用哪种View和ViewModel, 并管理View在scrollView中如何放置
 * 该类被相应的ScrollView拥有 */
@protocol SWRefreshHeaderController <NSObject>

@required

@property (nonatomic, strong) __kindof UIView<SWRefreshView>* headerView;
@property (nonatomic, strong) __kindof SWRefreshHeaderViewModel* headerModel;

/** this object owned by the scrollView, and the scrollView set this property
 * you may need to chain this property to ViewModel */
@property (nonatomic, assign) UIScrollView* scrollView;

@optional
/** offset for pos headerView */
@property (nonatomic) CGFloat headerOffset;

/** must implement if used as SWRefreshView default controller class! */
+ (instancetype)newWithHeaderView:(UIView<SWRefreshView>*)headerView model:(SWRefreshHeaderViewModel*)model;

@end


#pragma mark - Footer Protocol
@protocol SWRefreshFooterController <NSObject>

@required
@property (nonatomic, strong) __kindof UIView<SWRefreshView>* footerView;
@property (nonatomic, strong) __kindof SWRefreshFooterViewModel* footerModel;

/** this object owned by the scrollView, and the scrollView set this property
 * you may need to chain this property to ViewModel */
@property (nonatomic, assign, nullable) UIScrollView* scrollView;

@optional

/** offset for pos footerView */
@property (nonatomic) CGFloat footerOffset;
@property (nonatomic) CGFloat footerVisibleThreshold;
@property (nonatomic) bool hideWhenNoMore;

/** must implement if used as SWRefreshView default controller class! */
+ (instancetype)newWithFooterView:(UIView<SWRefreshView>*)footerView model:(SWRefreshFooterViewModel*)model;

@end

NS_ASSUME_NONNULL_END
