
//
//  DetailDownImageController.swift
//  SwiftTestDemo
//
//  Created by keyan on 16/7/1.
//  Copyright © 2016年 keyan. All rights reserved.
//

import UIKit
import Alamofire
class DetailDownImageController: UIViewController {

    let URLStringImage = "http://img.pconline.com.cn/images/photoblog/1/7/7/4/1774994/20063/28/1143511691007.JPG"
    
    var imagePath = ""

    @IBOutlet weak var imageView: UIImageView!
    
    @IBOutlet weak var progressLabe: UILabel!
    override func viewDidLoad() {
        super.viewDidLoad()


        Alamofire.download(.GET, URLStringImage) { (url, response) -> NSURL in
            self.imagePath = NSHomeDirectory() + "/" + (response.suggestedFilename ?? "01.png")
            let fileManager = NSFileManager.defaultManager()
            if fileManager.fileExistsAtPath(self.imagePath) {
                try? fileManager.removeItemAtPath(self.imagePath)
            }
            return NSURL(fileURLWithPath: self.imagePath)
            }.progress { (readBytes, totalReadBytes, totalBytes) -> Void in
                let progress = Int(Double(totalReadBytes) / Double(totalBytes) * 100)
                dispatch_async(dispatch_get_main_queue(), { () -> Void in
                    self.progressLabe.text = "\(progress)%"
                })
            }.response(queue: dispatch_get_main_queue()) { (_, _, _, error) -> Void in
                if let error = error {
                    print(error)
                } else {
                    self.progressLabe.hidden = true
                    self.imageView.image = UIImage(contentsOfFile: self.imagePath)
                }
        }

        
        
        // Do any additional setup after loading the view.
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
