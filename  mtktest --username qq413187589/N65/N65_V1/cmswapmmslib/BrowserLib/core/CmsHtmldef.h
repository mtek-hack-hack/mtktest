/*=============================================================

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

=============================================================

 Project Name: mini_Browser Ver3.20
 
 File Name   : CmsHtmldef.h

 Description : HTML Element Marco

 Last Modify : 02/18/2003
 
 Written By  : Mobilesoft

=============================================================*/

#ifndef CMSHTMLDEF_H
#define CMSHTMLDEF_H

/*=============================================================*/

/*=== WEB元素定义 ===*/

#define HTML_EL_ABBR 				0
#define HTML_EL_ACRONYM 			1
#define HTML_EL_Address 			2
#define HTML_EL_Anchor 				3
#define HTML_EL_Applet 				4
#define HTML_EL_AREA 				5
#define HTML_EL_BASE 				6
#define HTML_EL_BaseFont 			7
#define HTML_EL_BDO 				8
#define HTML_EL_Big_text 			9
#define HTML_EL_Block_Quote 		10
#define HTML_EL_BODY 				11
#define HTML_EL_Bold_text 			12
#define HTML_EL_BR 					13
#define HTML_EL_BUTTON 				14
#define HTML_EL_CAPTION 			15
#define HTML_EL_Center 				16
#define HTML_EL_Cite 				17
#define HTML_EL_Code 				18
#define HTML_EL_Data_cell 			19
#define HTML_EL_Def 				20
#define HTML_EL_Definition 			21
#define HTML_EL_Definition_List 	22
#define HTML_EL_DEL 				23
#define HTML_EL_Directory 			24
#define HTML_EL_Division 			25
#define HTML_EL_Emphasis 			26
#define HTML_EL_Font 				27
#define HTML_EL_Form 				28
#define HTML_EL_FRAME 				29
#define HTML_EL_FRAMESET 			30
#define HTML_EL_H1 					31
#define HTML_EL_H2 					32
#define HTML_EL_H3 					33
#define HTML_EL_H4 					34
#define HTML_EL_H5 					35
#define HTML_EL_H6 					36
#define HTML_EL_HEAD 				37
#define HTML_EL_Heading_cell 		38
#define HTML_EL_Horizontal_Rule 	39
#define HTML_EL_HTML 				40
#define HTML_EL_IFRAME 				41
#define HTML_EL_Input 				42
#define HTML_EL_INS 				43
#define HTML_EL_ISINDEX 			44
#define HTML_EL_Italic_text 		45
#define HTML_EL_Keyboard 			46
#define HTML_EL_LABEL 				47
#define HTML_EL_LINK 				48
#define HTML_EL_List_Item 			49
#define HTML_EL_MAP 				50
#define HTML_EL_Math 				51
#define HTML_EL_Menu 				52
#define HTML_EL_META 				53
#define HTML_EL_NOFRAMES 			54
#define HTML_EL_NOSCRIPT 			55
#define HTML_EL_Numbered_List 		56
#define HTML_EL_Object 				57
#define HTML_EL_Option 				58
#define HTML_EL_Option_Menu 		59
#define HTML_EL_Paragraph 			60
#define HTML_EL_Parameter 			61
#define HTML_EL_PICTURE_UNIT 		62
#define HTML_EL_Preformatted 		63
#define HTML_EL_Pseudo_paragraph 	64
#define HTML_EL_Quotation 			65
#define HTML_EL_Sample 				66
#define HTML_EL_SCRIPT 				67
#define HTML_EL_Small_text 			68
#define HTML_EL_Span 				69
#define HTML_EL_Strong 				70
#define HTML_EL_Struck_text 		71
#define HTML_EL_STYLE 				72
#define HTML_EL_Subscript 			73
#define HTML_EL_Superscript 		74
#define HTML_EL_Table 				75
#define HTML_EL_Table_row 			76
#define HTML_EL_tbody 				77
#define HTML_EL_Teletype_text 		78
#define HTML_EL_Term 				79
#define HTML_EL_Text_Area 			80
#define HTML_EL_TEXT_UNIT 			81
#define HTML_EL_tfoot 				82
#define HTML_EL_thead 				83
#define HTML_EL_TITLE 				84
#define HTML_EL_Underlined_text 	85
#define HTML_EL_Unnumbered_List 	86
#define HTML_EL_Variable 			87
#define HTML_EL_XMLGraphics 		88
#define HTML_EL_Text_Input 			89
#define HTML_EL_Password_Input 		90
#define HTML_EL_File_Input 			91
#define HTML_EL_Text_With_Frame 	92
#define HTML_EL_Inserted_Text 		93
#define HTML_EL_Button_Input 		94
#define HTML_EL_Checkbox_Input 		95
#define HTML_EL_Hidden_Input 		96
#define HTML_EL_Radio_Input 		97
#define HTML_EL_Reset_Input 		98
#define HTML_EL_Submit_Input 		99
#define HTML_EL_Comment 			100
#define HTML_EL_Object_Content 		101
#define HTML_EL_Frames 				102
#define HTML_EL_Frame 				103
#define HTML_EL_Comment_line 		104
#define HTML_EL_Styles 				105
#define HTML_EL_Scripts 			106
#define HTML_EL_Metas 				107
#define HTML_EL_Links 				108
#define HTML_EL_Document_URL 		109
#define HTML_EL_Term_List 			110
#define HTML_EL_Definition_Item 	111
#define HTML_EL_Element 			112
#define HTML_EL_NOBR 				113
#define HTML_EL_Column_head 		114
#define HTML_EL_Table_body 			115
#define HTML_EL_Table_head 			116
#define HTML_EL_Table_foot 			117
#define HTML_EL_Table_cell 			118
#define HTML_EL_Spacer  			119
#define HTML_EL_Invalid_element 	120
#define HTML_EL_MARQUEE   			121 
#define HTML_EL_IWDATAENTRY  		122
#define HTML_EL_Image_Input 		123	
#define HTML_EL_NULL  				124 
#define HTML_EL_ENDNOFRAMES 		125
#define HTML_EL_ENDFRAMESET 		126

/*=== WML元素定义 ===*/

#define WML_EL_WML 					127
#define WML_EL_CARD 				128
#define WML_EL_TEMPLATE 			129
#define WML_EL_HEAD 				130
#define WML_EL_ACCESS 				131
#define WML_EL_META 				132
#define WML_EL_TIMER 				133
#define WML_EL_SETVAR 				134
#define WML_EL_ANCHOR 				135
#define WML_EL_A 					136
#define WML_EL_DO 					137
#define WML_EL_ONEVENT 				138
#define WML_EL_GO 					139
#define WML_EL_PREV 				140
#define WML_EL_NOOP 				141
#define WML_EL_REFRESH 				142
#define WML_EL_INPUT 				143
#define WML_EL_SELECT 				144
#define WML_EL_OPTION 				145
#define WML_EL_OPTGROUP 			146
#define WML_EL_FIELDSET 			147
#define WML_EL_IMG 					148
#define WML_EL_TABLE 				149
#define WML_EL_TD 					150
#define WML_EL_TR 					151
#define WML_EL_B 					152
#define WML_EL_BIG 					153
#define WML_EL_BR 					154
#define WML_EL_EM 					155
#define WML_EL_I 					156
#define WML_EL_P 					157
#define WML_EL_SMALL 				158
#define WML_EL_STRONG 				159
#define WML_EL_U 					160
#define WML_EL_POSTFIELD 			161
#define WML_EL_ENDDO 				162
#define WML_EL_ENDONEVENT 			163
#define WML_EL_ENDGO      			164
#define WML_EL_ENDANCHOR     		165

/*=== PUSH元素定义 ===*/

#define PUSH_EL_SL 					166
#define PUSH_EL_SI 					167
#define PUSH_EL_INDICATION 			168
#define PUSH_EL_INFO 				169
#define PUSH_EL_ITEM 				170

/*=== 2004-10-30 Accesskey&BGSound ===*/
#define HTML_EL_BGSOUND  			171 
/*=== 2004-10-30 Accesskey&BGSound end ===*/

/*=== xml元素定义 ===*/
#define XML_EL_XML					172


#define HTML_EL_End_Quote			173
#define HTML_EL_End_Numbered_List	174
#define HTML_EL_End_Unnumbered_List 175
#define HTML_EL_ENDFORM				176

#define HTML_EL_ENDHEAD             177
#define HTML_EL_EndPragraph         178

#define HTML_EL_End_Definition_List 179
#define HTML_EL_ENDFont             180//jiezhang 9.18

/*=== HTML常用属性定义 ===*/

#define HTML_ATTR_abbr 						0
#define HTML_ATTR_accept 					1
#define HTML_ATTR_accept_charset 			2
#define HTML_ATTR_accesskey 				3
#define HTML_ATTR_ActiveLinkColor 			4
#define HTML_ATTR_Align 					5
#define HTML_ATTR_Alignment 				6
#define HTML_ATTR_ALT 						7
#define HTML_ATTR_applet_name 				8
#define HTML_ATTR_archive 					9
#define HTML_ATTR_Area_Size 				10
#define HTML_ATTR_Associated_control 		11
#define HTML_ATTR_axis 						12
#define HTML_ATTR_BackgroundColor 			13
#define HTML_ATTR_background				14
#define HTML_ATTR_BaseFontColor 			15
#define HTML_ATTR_BaseFontFace 				16
#define HTML_ATTR_BaseFontSize 				17
#define HTML_ATTR_Border 					18
#define HTML_ATTR_BulletStyle 				19
#define HTML_ATTR_Button_type 				20
#define HTML_ATTR_cellpadding 				21
#define HTML_ATTR_cellspacing 				22
#define HTML_ATTR_Cell_align 				23
#define HTML_ATTR_Cell_valign 				24
#define HTML_ATTR_char 						25
#define HTML_ATTR_charoff 					26
#define HTML_ATTR_charset 					27
#define HTML_ATTR_Checked 					28
#define HTML_ATTR_cite 						29
#define HTML_ATTR_Class 					30
#define HTML_ATTR_classid 					31
#define HTML_ATTR_Clear 					32
#define HTML_ATTR_code 						33
#define HTML_ATTR_codebase 					34
#define HTML_ATTR_codetype 					35
#define HTML_ATTR_color 					36
#define HTML_ATTR_colspan 					37
#define HTML_ATTR_Columns 					38
#define HTML_ATTR_ColWidth 					39
#define HTML_ATTR_COMPACT 					40
#define HTML_ATTR_content_type 				41
#define HTML_ATTR_coords 					42
#define HTML_ATTR_data 						43
#define HTML_ATTR_datapagesize 				44
#define HTML_ATTR_datetime 					45
#define HTML_ATTR_declare 					46
#define HTML_ATTR_defer 					47
#define HTML_ATTR_dir 						48
#define HTML_ATTR_disabled 					49
#define HTML_ATTR_ENCTYPE 					50
#define HTML_ATTR_event 					51
#define HTML_ATTR_face 						52
#define HTML_ATTR_Font_size 				53
#define HTML_ATTR_for 						54
#define HTML_ATTR_frame 					55
#define HTML_ATTR_frameborder 				56
#define HTML_ATTR_FrameName 				57
#define HTML_ATTR_FrameSrc 					58
#define HTML_ATTR_Ghost_restruct 			59
#define HTML_ATTR_headers 					60
#define HTML_ATTR_Height 					61
#define HTML_ATTR_hreflang 					62
#define HTML_ATTR_HREF 						63
#define HTML_ATTR_hspace 					64
#define HTML_ATTR_http_equiv 				65
#define HTML_ATTR_ID 						66
#define HTML_ATTR_Img_border 				67
#define HTML_ATTR_Invalid_attribute 		68
#define HTML_ATTR_ISMAP 					69
#define HTML_ATTR_ItemStyle 				70
#define HTML_ATTR_ItemValue 				71
#define HTML_ATTR_label 					72
#define HTML_ATTR_Langue 					73
#define HTML_ATTR_LinkColor 				74
#define HTML_ATTR_Link_type 				75
#define HTML_ATTR_longdesc 					76
#define HTML_ATTR_marginheight 				77
#define HTML_ATTR_marginwidth 				78
#define HTML_ATTR_MaxLength 				79
#define HTML_ATTR_media 					80
#define HTML_ATTR_MenuSize 					81
#define HTML_ATTR_meta_content 				82
#define HTML_ATTR_meta_name 				83
#define HTML_ATTR_METHOD 					84
#define HTML_ATTR_mode 						85
#define HTML_ATTR_Multiple 					86
#define HTML_ATTR_NAME   					87
#define HTML_ATTR_nohref 					88
#define HTML_ATTR_NoShade 					89
#define HTML_ATTR_Notation 					90
#define HTML_ATTR_no_resize 				91
#define HTML_ATTR_No_wrap 					92
#define HTML_ATTR_NumberStyle 				93
#define HTML_ATTR_object 					94
#define HTML_ATTR_Object_type 				95
#define HTML_ATTR_onblur 					96
#define HTML_ATTR_onchange 					97
#define HTML_ATTR_onclick 					98
#define HTML_ATTR_ondblclick 				99
#define HTML_ATTR_onfocus 					100
#define HTML_ATTR_onkeydown 				101
#define HTML_ATTR_onkeypress 				102
#define HTML_ATTR_onkeyup 					103
#define HTML_ATTR_onload 					104
#define HTML_ATTR_onmousedown 				105
#define HTML_ATTR_onmousemove 				106
#define HTML_ATTR_onmouseout 				107
#define HTML_ATTR_onmouseover 				108
#define HTML_ATTR_onmouseup 				109
#define HTML_ATTR_onreset 					110
#define HTML_ATTR_onselect 					111
#define HTML_ATTR_onsubmit 					112
#define HTML_ATTR_onunload 					113
#define HTML_ATTR_Param_name 				114
#define HTML_ATTR_Param_type 				115
#define HTML_ATTR_Param_value 				116
#define HTML_ATTR_Position 					117
#define HTML_ATTR_profile 					118
#define HTML_ATTR_Prompt 					119
#define HTML_ATTR_readonly 					120
#define HTML_ATTR_REL 						121
#define HTML_ATTR_REV 						122
#define HTML_ATTR_RowHeight 				123
#define HTML_ATTR_Rows 						124
#define HTML_ATTR_rowspan					125
#define HTML_ATTR_Row_valign 				126
#define HTML_ATTR_rules 					127
#define HTML_ATTR_scheme 					128
#define HTML_ATTR_scope 					129
#define HTML_ATTR_script_language 			130
#define HTML_ATTR_script_src 				131
#define HTML_ATTR_Script_URL 				132
#define HTML_ATTR_scrolling 				133
#define HTML_ATTR_Selected 					134
#define HTML_ATTR_shape 					135
#define HTML_ATTR_Size 						136
#define HTML_ATTR_SRC 						137
#define HTML_ATTR_standby 					138
#define HTML_ATTR_Start 					139
#define HTML_ATTR_Style 					140
#define HTML_ATTR_summary 					141
#define HTML_ATTR_tabindex 					142
#define HTML_ATTR_target 					143
#define HTML_ATTR_TextAlign 				144
#define HTML_ATTR_TextColor 				145
#define HTML_ATTR_Title 					146
#define HTML_ATTR_USEMAP 					147
#define HTML_ATTR_valuetype 				148
#define HTML_ATTR_Value 					149
#define HTML_ATTR_VisitedLinkColor 			150
#define HTML_ATTR_vspace 					151
#define HTML_ATTR_Width						152
#define HTML_ATTR_x_coord 					153
#define HTML_ATTR_y_coord 					154
#define HTML_ATTR_IntWidthPxl 				155
#define HTML_ATTR_DefaultChecked_VAL_Yes 	156
#define HTML_ATTR_DefaultSelected 			157
#define HTML_ATTR_Default_Value 			158
#define HTML_ATTR_IntItemStyle 				159
#define HTML_ATTR_Error_type 				160
#define HTML_ATTR_PseudoClass 				161
#define HTML_ATTR_DefaultChecked 			162
#define HTML_ATTR_IntWidthPercent 			163
#define HTML_ATTR_IntSizeIncr 				164
#define HTML_ATTR_IntSizeDecr 				165
#define HTML_ATTR_IntSizeRel 				166
#define HTML_ATTR_Ref_column 				167
#define HTML_ATTR_RowExt 					168
#define HTML_ATTR_ColExt 					169
#define HTML_ATTR_NULL  					170  
#define HTML_ATTR_spacetype 				171
#define HTML_ATTR_LENGTH 					172
#define HTML_ATTR_TYPE 						173
#define HTML_ATTR_scrolldelay 				174
#define HTML_ATTR_scrollamount 				175
#define HTML_ATTR_option_onpick  			176
#define HTML_ATTR_HTTP_EQUIV    			177
#define HTML_ATTR_meta_URL 					178

/*=== WML属性定义 ===*/

#define WML_ATTR_ontimer 					179
#define WML_ATTR_DO_TYPE 					180
#define WML_ATTR_ONEVENT_TYPE 				181
#define WML_ATTR_DO_optional 				182
#define WML_ATTR_CARD_newcontext 			183
#define WML_ATTR_CARD_onenterbackward 		184
#define WML_ATTR_CARD_onenterforward 		185

/*=== PUSH属性定义 ===*/

#define PUSH_ATTR_action 					186
#define PUSH_ATTR_SI_created 				187
#define PUSH_ATTR_SI_expires 				188
#define PUSH_ATTR_SI_siid 					189
#define PUSH_ATTR_SI_class 					190


/*=== PICTOGRAM 属性定义 ===*/
#define HTML_ATTR_PICTO_LOCALSRC			191

/*=== 2004-10-30 Accesskey&BGSound ===*/
/*=== BGSOUND的循环播放属性定义 ===*/
#define HTML_ATTR_loop 						192
/*=== 2004-10-30 Accesskey&BGSound end ===*/

/*=== XTML常用属性定义 ===*/
#define HTML_ATTR_VERSION					192
#define HTML_ATTR_ENCODING					192
#define HTML_ATTR_FORMAT					193
#define HTML_ATTR_Selected_Default			194
#define HTML_ATTR_Valign					195


/*=== HTML非常用属性定义 ===*/

#define HTML_ATTR_Alignment_VAL_Bottom_ 		0
#define HTML_ATTR_Alignment_VAL_Left_ 			1
#define HTML_ATTR_Alignment_VAL_Middle_ 		2
#define HTML_ATTR_Alignment_VAL_Right_ 			3
#define HTML_ATTR_Alignment_VAL_Top_ 			4
#define HTML_ATTR_Align_VAL_center_ 			5
#define HTML_ATTR_Align_VAL_left_ 				6
#define HTML_ATTR_Align_VAL_right_ 				7
#define HTML_ATTR_BulletStyle_VAL_circle 		8
#define HTML_ATTR_BulletStyle_VAL_disc 			9
#define HTML_ATTR_BulletStyle_VAL_square 		10
#define HTML_ATTR_Button_type_VAL_button 		11
#define HTML_ATTR_Button_type_VAL_reset 		12
#define HTML_ATTR_Button_type_VAL_submit 		13
#define HTML_ATTR_Cell_align_VAL_Cell_center 	14
#define HTML_ATTR_Cell_align_VAL_Cell_char 		15
#define HTML_ATTR_Cell_align_VAL_Cell_justify 	16
#define HTML_ATTR_Cell_align_VAL_Cell_left 		17
#define HTML_ATTR_Cell_align_VAL_Cell_right		18
#define HTML_ATTR_Cell_valign_VAL_Cell_baseline 19
#define HTML_ATTR_Cell_valign_VAL_Cell_bottom 	20
#define HTML_ATTR_Cell_valign_VAL_Cell_middle 	21
#define HTML_ATTR_Cell_valign_VAL_Cell_top 		22
#define HTML_ATTR_Checked_VAL_Yes_ 				23
#define HTML_ATTR_Clear_VAL_All_ 				24
#define HTML_ATTR_Clear_VAL_Left_ 				25
#define HTML_ATTR_Clear_VAL_None 				26
#define HTML_ATTR_Clear_VAL_Right_ 				27
#define HTML_ATTR_COMPACT_VAL_Yes_ 				28
#define HTML_ATTR_declare_VAL_Yes_ 				29
#define HTML_ATTR_defer_VAL_Yes_ 				30
#define HTML_ATTR_dir_VAL_ltr 					31
#define HTML_ATTR_dir_VAL_rtl 					32
#define HTML_ATTR_disabled_VAL_Yes_ 			33
#define HTML_ATTR_frameborder_VAL_Border0 		34
#define HTML_ATTR_frameborder_VAL_Border1 		35
#define HTML_ATTR_frame_VAL_above 				36
#define HTML_ATTR_frame_VAL_below 				37
#define HTML_ATTR_frame_VAL_border 				38
#define HTML_ATTR_frame_VAL_box 				39
#define HTML_ATTR_frame_VAL_hsides 				40
#define HTML_ATTR_frame_VAL_lhs 				41
#define HTML_ATTR_frame_VAL_rhs 				42
#define HTML_ATTR_frame_VAL_void 				43
#define HTML_ATTR_frame_VAL_vsides 				44
#define HTML_ATTR_ISMAP_VAL_Yes_ 				45
#define HTML_ATTR_ItemStyle_VAL_Arabic_ 		46
#define HTML_ATTR_ItemStyle_VAL_circle 			47
#define HTML_ATTR_ItemStyle_VAL_disc 			48
#define HTML_ATTR_ItemStyle_VAL_LowerAlpha 		49
#define HTML_ATTR_ItemStyle_VAL_LowerRoman 		50
#define HTML_ATTR_ItemStyle_VAL_square 			51
#define HTML_ATTR_ItemStyle_VAL_UpperAlpha 		52
#define HTML_ATTR_ItemStyle_VAL_UpperRoman 		53
#define HTML_ATTR_METHOD_VAL_Get_ 				54
#define HTML_ATTR_METHOD_VAL_Post_ 				55
#define HTML_ATTR_mode_VAL_display 				56
#define HTML_ATTR_mode_VAL_inline_math 			57
#define HTML_ATTR_Multiple_VAL_Yes_ 			58
#define HTML_ATTR_nohref_VAL_Yes_ 				59
#define HTML_ATTR_NoShade_VAL_NoShade_ 			60
#define HTML_ATTR_No_wrap_VAL_no_wrap 			61
#define HTML_ATTR_NumberStyle_VAL_Arabic_ 		62
#define HTML_ATTR_NumberStyle_VAL_LowerAlpha 	63
#define HTML_ATTR_NumberStyle_VAL_LowerRoman 	64
#define HTML_ATTR_NumberStyle_VAL_UpperAlpha 	65
#define HTML_ATTR_NumberStyle_VAL_UpperRoman 	66
#define HTML_ATTR_Position_VAL_Position_bottom 	67
#define HTML_ATTR_Position_VAL_Position_left 	68
#define HTML_ATTR_Position_VAL_Position_right 	69
#define HTML_ATTR_Position_VAL_Position_top 	70
#define HTML_ATTR_readonly_VAL_Yes_ 			71
#define HTML_ATTR_Row_valign_VAL_Row_baseline 	72
#define HTML_ATTR_Row_valign_VAL_Row_bottom 	73
#define HTML_ATTR_Row_valign_VAL_Row_middle 	74
#define HTML_ATTR_Row_valign_VAL_Row_top 		75
#define HTML_ATTR_rules__VAL_all 				76
#define HTML_ATTR_rules__VAL_cols 				77
#define HTML_ATTR_rules__VAL_groups 			78
#define HTML_ATTR_rules__VAL_none 				79
#define HTML_ATTR_rules__VAL_rows 				80
#define HTML_ATTR_scrolling_VAL_auto 			81
#define HTML_ATTR_scrolling_VAL_No_ 			82
#define HTML_ATTR_scrolling_VAL_Yes_ 			83
#define HTML_ATTR_Selected_VAL_Yes_ 			84
#define HTML_ATTR_shape_VAL_circle 				85
#define HTML_ATTR_shape_VAL_polygon 			86
#define HTML_ATTR_shape_VAL_rectangle 			87
#define HTML_ATTR_TextAlign_VAL_center_ 		88
#define HTML_ATTR_TextAlign_VAL_justify_ 		89
#define HTML_ATTR_TextAlign_VAL_left_ 			90
#define HTML_ATTR_TextAlign_VAL_right_ 			91
#define HTML_ATTR_valuetype_VAL_data_ 			92
#define HTML_ATTR_valuetype_VAL_object_ 		93
#define HTML_ATTR_valuetype_VAL_ref 			94
#define HTML_ATTR_DefaultSelected_VAL_Yes_ 		95
#define HTML_ATTR_Checked_VAL_No_ 				96
#define HTML_ATTR_IntItemStyle_VAL_disc 		97
#define HTML_ATTR_IntItemStyle_VAL_Arabic_ 		98
#define HTML_ATTR_IntItemStyle_VAL_LowerAlpha 	99
#define HTML_ATTR_IntItemStyle_VAL_UpperAlpha 	100
#define HTML_ATTR_IntItemStyle_VAL_LowerRoman 	101
#define HTML_ATTR_IntItemStyle_VAL_UpperRoman 	102
#define HTML_ATTR_IntItemStyle_VAL_circle 		103
#define HTML_ATTR_IntItemStyle_VAL_square 		104
#define HTML_ATTR_Error_type_VAL_BadPosition 	105
#define HTML_ATTR_Error_type_VAL_UnknownTag 	106
#define HTML_ATTR_direction  					107
#define HTML_ATTR_Spahei 						108

#define HTML_ELE_ATTR_NOT_FOUND					0xFFFFFFFF


#endif
