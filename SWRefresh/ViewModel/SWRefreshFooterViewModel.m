//
//  SWRefreshFooterViewModel.m
//  SWRefresh
//
//  Created by Li Xiangming on 18/12/31.
//  Copyright © 2015年 SWRefresh All rights reserved.
//

#import "SWRefreshFooterViewModel.h"

@implementation SWRefreshFooterViewModel

- (void)endRefreshingWithNoMoreData:(BOOL)animated {
    return [self endRefreshingWithState:SWRefreshStateNoMoreData
                               animated:animated
                                 reason:SWRefreshEndRefreshSuccessToken];
}

- (void)resetNoMoreData {
    if (self.state == SWRefreshStateNoMoreData) {
        self.state = SWRefreshStateIdle;
    }
}


@end
