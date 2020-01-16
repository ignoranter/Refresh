//
//  SWRefreshHeaderViewModel.m
//  SWRefresh
//
//  Created by Li Xiangming on 18/12/31.
//  Copyright © 2015年 SWRefresh All rights reserved.
//

#import "SWRefreshHeaderViewModel.h"

@implementation SWRefreshHeaderViewModel

- (void)unbindScrollView:(UIScrollView *)scrollView {
    [super unbindScrollView:scrollView];
    
    if (self.state == SWRefreshStateRefreshing) {
        self.state = SWRefreshStateIdle;
    }
}

- (void)scrollViewContentOffsetDidChange:(NSDictionary *)change {
    CGPoint offset = self.scrollView.contentOffset;
    UIEdgeInsets _scrollViewOriginInsets = self.scrollViewOriginInsets;
    if (self.state == SWRefreshStateRefreshing) {
        if (self.scrollView.dragging) {
            // Keep header, inset 应该在 origin top inset 和 加上高度之前
            UIEdgeInsets inset = self.scrollView.contentInset;
            inset.top = -offset.y;
            if (inset.top < _scrollViewOriginInsets.top) {
                inset.top = _scrollViewOriginInsets.top;
            }
            else if (inset.top > _refreshThreshold + _scrollViewOriginInsets.top) {
                inset.top = _refreshThreshold + _scrollViewOriginInsets.top;
            }
            [self setScrollViewTempInset:inset];
        }
        return;
    }

    // inset可能改变, 改为父类监听修改
    // _scrollViewOriginInsets = self.scrollView.contentInset;

    CGFloat happendOffsetY = -_scrollViewOriginInsets.top;

    // not reach critical offset
    if ( happendOffsetY < offset.y ) return;

    CGFloat pullingPercent = (happendOffsetY - offset.y) / _refreshThreshold;

    if (self.scrollView.isDragging) {
        CGFloat pullingOffsetY = happendOffsetY - _refreshThreshold;
        self.pullingPercent = pullingPercent;

        if (self.state == SWRefreshStateIdle) {
            if (offset.y < pullingOffsetY) {
                self.state = SWRefreshStatePulling;
            }
        } else if (self.state == SWRefreshStatePulling) {
            if (offset.y > pullingOffsetY) {
                self.state = SWRefreshStateIdle;
            }
        }
    } else if (self.state == SWRefreshStatePulling) { // pulling状态下松开
        [self beginRefreshing:YES];
    } else if (pullingPercent < 1) {
        self.pullingPercent = pullingPercent;
    }
}

- (void)changeFromState:(SWRefreshState)oldState to:(SWRefreshState)newState {
    NSAssert([NSThread isMainThread], @"should change state in main thread!");
    
    if (!self.weakScrollView) {return;}

    UIEdgeInsets inset = self.scrollView.contentInset;
    
    if (oldState == SWRefreshStateRefreshing) {
        // 恢复inset, 只更改top
        inset.top = self.scrollViewOriginInsets.top;
        [self setScrollViewTempInset:inset];
    } else if (newState == SWRefreshStateRefreshing) {
        // 保持inset, 只更改top
        inset.top = _refreshThreshold + self.scrollViewOriginInsets.top;
        [self setScrollViewTempInset:inset];

        if (_scrollsToTopWhenRefreshing) {
            CGPoint p = self.scrollView.contentOffset;
            p.y = -inset.top;
            self.scrollView.contentOffset = p;
        }
    }
}

@end
