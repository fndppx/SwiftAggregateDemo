//
//  NetWorkManager.swift
//  SwiftTestDemo
//
//  Created by keyan on 16/7/1.
//  Copyright © 2016年 keyan. All rights reserved.
//

//typealias VHHorSegmentViewBlock = (index: Int) -> ()
let   VHNET_HOSTURL = "https://api.app.vhall.com/"
let   VHNET_INTERFACE_VER = "v5/000/"

import UIKit
import Alamofire
import SwiftyJSON
class NetWorkManager: NSObject {

    
      func requestWithAla(op : String, getparams  : NSDictionary?,  postparmas : NSDictionary? ) {
        var  url:NSMutableString = VHNET_HOSTURL+VHNET_INTERFACE_VER+op as! NSMutableString
        
        if (getparams != nil)  {
            let mykey:NSArray = (getparams?.allKeys)!
            
            for key  in mykey {
                url.appendString(key as! String)
                url.appendString("=")
                let temp:String = (getparams?.objectForKey(key))! as! String
                url.appendString(urlEncodeUTF8String(temp))
                url.appendString("&")
            }
            
        }
        
        
        
        
        url.appendString("atom=")
        url.appendString(UlityTools.atomSting(VHStatisticsStystem.sharedManager().getAtomDic()))
        url.appendString("atom=")
        
        var rand:String = NSString.init() as String
        for i in 0..<5 {
            let number = arc4random()%36
            if number<10 {
                let figure = arc4random()%10
                let tempString = NSString.init()
                rand = rand.stringByAppendingString(tempString as String)
                
                
            }
            else
            {
                let figure = (arc4random()%26)+97
                let tempString:String = ("\(figure)")
                rand = rand.stringByAppendingString(tempString)
            
            }
            
        }
        url.appendString(rand)
        let sign = VHTools.MD5WithUrl(url as String, param: postparmas as! [NSObject : AnyObject] )
        
        url.appendString("&sign=")
        url.appendString(sign)
        
        let URLString = "https://api.douban.com/v2/book/search"
        
        
        Alamofire.request(.GET, URLString, parameters: ["tag":"Swift","count":10]).validate().responseJSON { (respose ) in
            print("\(respose)")
            if let error = respose.result.error {
                print(error)
            } else if let value = respose.result.value,jsonArray = JSON(value)["books"].array {
//                for json in jsonArray {
//                    let book = TestModel()
//                    book.title = json["title"].string ?? ""
//                    book.subtitle = json["subtitle"].string ?? ""
//                    book.image = json["image"].string ?? ""
//                    self.books.append(book)
//                }
//                self.tableView.reloadData()
            }
            
        }
  
        
    }
    
    
    func urlEncodeUTF8String(input: String) -> String {
        let outputStr = input.stringByAddingPercentEscapesUsingEncoding(NSUTF8StringEncoding)
        return outputStr!
        
    }
}


