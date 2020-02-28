
void read_BPM(){
  ThisTime=millis();
  int val=analogRead(A0);
  printline_oled(val);
  
  Serial.println(val);
 
    if(val>UpperThreshold)
  {
  if(BeatComplete)
  {
  BPM=ThisTime-LastTime;
  BPM=int(60/(float(BPM)/1000));
  count+=1;
  BPM2=BPM2+BPM;
  if(count==50){
    BPM1=int(BPM2/count);
    
    BPM2=0;
    count=0;
  }
  BPMTiming=false;
  BeatComplete=false;
  }
  if(BPMTiming==false)
  {
  LastTime=millis();
  BPMTiming=true;
  }
  }
  if((val<LowerThreshold)&(BPMTiming))
    BeatComplete=true;
    print_oled("BPM: "+String(BPM1),2);
    //Serial.println("BPM :" + String(BPM1));
  
  }
