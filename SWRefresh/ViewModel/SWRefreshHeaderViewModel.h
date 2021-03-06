//
//  SWRefreshHeaderViewModel.h
//  SWRefresh
//
//  Created by Li Xiangming on 18/12/31.
//  Copyright © 2015年 SWRefresh All rights reserved.
//

#import "SWRefreshViewModel.h"

@interface SWRefreshHeaderViewModel : SWRefreshViewModel

@property (nonatomic, assign) CGFloat refreshThreshold; ///< amout scrollView need to beyond
@property (nonatomic) bool scrollsToTopWhenRefreshing; ///< whether scrollToTop when enter refreshing, default NO

@end
