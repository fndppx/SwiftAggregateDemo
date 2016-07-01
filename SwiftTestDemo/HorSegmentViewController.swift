

//
//  HorSegmentViewController.swift
//  SwiftTestDemo
//
//  Created by keyan on 16/6/29.
//  Copyright © 2016年 keyan. All rights reserved.
//

import UIKit

class HorSegmentViewController: UIViewController {

    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.title = "SegmentView"
        // Do any additional setup after loading the view.
        self.edgesForExtendedLayout = UIRectEdge.None
        print("\(NSStringFromCGRect(self.view.frame))")

        let dataArray:[String] = ["第一个","第二个","第三个","第三个","第三个","第一个","第二个","第三个","第三个","第三个"]
        
        let segmentView = VHHorSegmentView.init(frame: CGRectMake(0, 50, self.view.frame.size.width, 50), dataArray: dataArray) { (index) in
            print("点击了第\(index)个")
        }
        self.view.addSubview(segmentView)
        
        
        

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
