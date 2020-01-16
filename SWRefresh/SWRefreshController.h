//
//  SWRefreshController.h
//  SWRefresh
//
//  Created by Li Xiangming on 18/12/14.
//  Copyright © 2016年 SWRefresh All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SWRefreshHeaderFooterProcotol.h"

#pragma mark - default Header Class

@interface SWRefreshHeaderController : NSObject <SWRefreshHeaderController>
/**insetTop for headerView, positive offset make headerView move to top*/
@property (nonatomic) CGFloat headerOffset;
@end


#pragma mark - default Footer Class
@interface SWRefreshFooterController : NSObject <SWRefreshFooterController>

/**insetBottom for footerView, positive offset make footerView move to bottom*/
@property (nonatomic) CGFloat footerOffset;
/** when content height below this threshold, footer will hide and disable. default 200 */
@property (nonatomic, assign) CGFloat footerVisibleThreshold;
/** when nomore state, hide footer */
@property (nonatomic) bool hideWhenNoMore;

@end
