define dso_local void @foo() {
  call void @__sdc_block_begin__(i32 noundef 0)
  call void @__sdc_block_end__(i32 noundef 0)
  call void @__sdc_api_begin__(i32 noundef 0)
  call void @__sdc_api_end__(i32 noundef 0)
  ret void
}

declare void @__sdc_block_begin__(i32 noundef)

declare void @__sdc_block_end__(i32 noundef)

declare void @__sdc_api_begin__(i32 noundef)

declare void @__sdc_api_end__(i32 noundef)

